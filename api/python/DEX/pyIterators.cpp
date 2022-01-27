/* Copyright 2017 - 2021 R. Thomas
 * Copyright 2017 - 2021 Quarkslab
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
#include "pyDEX.hpp"
#include "pyIterators.hpp"

#include "LIEF/DEX/type_traits.hpp"

namespace LIEF {
namespace DEX {

void init_iterators(py::module& m) {
  init_ref_iterator<it_dex_files>(m, "it_dex_files");
  init_ref_iterator<it_classes>(m, "it_classes");
  init_ref_iterator<it_methods>(m, "it_methods");
  init_ref_iterator<it_fields>(m, "it_fields");
  init_ref_iterator<it_strings>(m, "it_strings");
  init_ref_iterator<it_protypes>(m, "it_protypes");
}

}
}
