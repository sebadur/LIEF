target_sources(LIB_LIEF PRIVATE
  Binary.cpp
  Binary.tcc
  Builder.cpp
  Builder.tcc
  Convert.cpp
  DataHandler/Handler.cpp
  DataHandler/Node.cpp
  DynamicEntry.cpp
  DynamicEntryArray.cpp
  DynamicEntryFlags.cpp
  DynamicEntryLibrary.cpp
  DynamicEntryRpath.cpp
  DynamicEntryRunPath.cpp
  DynamicSharedObject.cpp
  EnumToString.cpp
  GnuHash.cpp
  Header.cpp
  Layout.cpp
  Note.cpp
  NoteDetails.cpp
  Parser.cpp
  Parser.tcc
  Relocation.cpp
  RelocationSizes.cpp
  Section.cpp
  Segment.cpp
  Symbol.cpp
  SymbolVersion.cpp
  SymbolVersionAux.cpp
  SymbolVersionAuxRequirement.cpp
  SymbolVersionDefinition.cpp
  SymbolVersionRequirement.cpp
  SysvHash.cpp
  hash.cpp
  note_utils.cpp
  utils.cpp
  json_api.cpp)

add_subdirectory(NoteDetails)
add_subdirectory(DataHandler)

if(LIEF_ENABLE_JSON)
  target_sources(LIB_LIEF PRIVATE json.cpp)
endif()
