/* Copyright 2017 - 2023 R. Thomas
 * Copyright 2017 - 2023 Quarkslab
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "PE/pyPE.hpp"
#include "pyIterator.hpp"

#include "LIEF/PE/RichHeader.hpp"

#include <string>
#include <sstream>
#include <nanobind/stl/string.h>
#include <nanobind/stl/vector.h>

namespace LIEF::PE::py {

template<>
void create<RichHeader>(nb::module_& m) {
  using namespace LIEF::py;

  nb::class_<RichHeader> rich(m, "RichHeader",
      R"delim(
      Class which represents the not-so-documented rich header

      This structure is usually located at the end of the :attr:`~lief.PE.Binary.dos_stub`
      and contains information about the build environment.

      It is generated by the Microsoft linker `link.exe` and there are no options to disable
      or remove this information.
      )delim"_doc);

  init_ref_iterator<RichHeader::it_entries>(rich, "it_entries");

  rich
    .def(nb::init<>())
    .def_prop_rw("key",
        nb::overload_cast<>(&RichHeader::key, nb::const_),
        nb::overload_cast<uint32_t>(&RichHeader::key),
        "Key used to encode the header (xor operation)"_doc)

    .def_prop_ro("entries",
        nb::overload_cast<>(&RichHeader::entries),
        "Return an iterator over the " RST_CLASS_REF(lief.PE.RichEntry) " within the header"_doc,
        nb::keep_alive<1, 0>())

    .def("add_entry",
        nb::overload_cast<const RichEntry&>(&RichHeader::add_entry),
        "Add a new " RST_CLASS_REF(lief.PE.RichEntry) ""_doc,
        "entry"_a)

    .def("add_entry",
        nb::overload_cast<uint16_t, uint16_t, uint32_t>(&RichHeader::add_entry),
        "Add a new " RST_CLASS_REF(lief.PE.RichEntry) " given its "
        ":attr:`~lief.PE.RichEntry.id`, "
        ":attr:`~lief.PE.RichEntry.build_id`, "
        ":attr:`~lief.PE.RichEntry.count`"_doc,
        "id"_a, "build_id"_a, "count"_a)

    .def("raw",
        nb::overload_cast<>(&RichHeader::raw, nb::const_),
        R"delim(
        The raw structure of the Rich header without xor-encoding.

        This function is equivalent as calling the other raw function with a `xor_key` set to 0
        )delim"_doc)

    .def("raw",
        nb::overload_cast<uint32_t>(&RichHeader::raw, nb::const_),
        R"delim(
        Given this rich header, this function re-computes
        the raw bytes of the structure with the provided xor-key.

        You can access the decoded data's structure with the `xor_key` set to 0
        )delim"_doc,
        "xor_key"_a)

    .def("hash",
        nb::overload_cast<ALGORITHMS>(&RichHeader::hash, nb::const_),
        R"delim(
        Compute the hash of the decoded rich header structure with the given hash :class:`~lief.PE.ALGORITHMS`
        )delim"_doc,
        "algo"_a)

    .def("hash",
        nb::overload_cast<ALGORITHMS, uint32_t>(&RichHeader::hash, nb::const_),
        R"delim(
        Compute the hash of the rich header structure encoded with the provided key and the given hash
        :class:`~lief.PE.ALGORITHMS`
        )delim"_doc,
        "algo"_a, "xor_key"_a)

    LIEF_DEFAULT_STR(RichHeader);
}

}
