// Copyright 2019 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <rosidl_typesupport_connext_cpp/wstring_conversion.hpp>

#ifdef __clang__
# pragma clang diagnostic push
# pragma clang diagnostic ignored "-Wdeprecated-register"
# pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
#endif
#include "ndds/ndds_cpp.h"
#ifdef __clang__
# pragma clang diagnostic pop
#endif

namespace rosidl_typesupport_connext_cpp
{

DDS_Wchar * create_wstring_from_u16string(const std::u16string & u16str)
{
  DDS_Wchar * wstr = DDS_Wstring_alloc(static_cast<DDS_Long>(u16str.size()));
  if (NULL == wstr) {
    return wstr;
  }
  for (size_t i = 0; i < u16str.size(); ++i) {
    wstr[i] = static_cast<DDS_Wchar>(u16str[i]);
  }
  wstr[u16str.size()] = static_cast<DDS_Wchar>(u'\0');
  return wstr;
}

bool wstring_to_u16string(const DDS_Wchar * wstr, std::u16string & u16str)
{
  size_t size = static_cast<size_t>(DDS_Wstring_length(wstr));
  try {
    u16str.resize(size);
  } catch (...) {
    return false;
  }
  for (size_t i = 0; i < size; ++i) {
    u16str[i] = static_cast<char16_t>(wstr[i]);
  }
  u16str[size] = u'\0';
  return true;
}

}  // namespace rosidl_typesupport_connext_cpp
