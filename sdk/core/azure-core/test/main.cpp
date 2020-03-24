// Copyright (c) Microsoft Corporation. All rights reserved.
// SPDX-License-Identifier: MIT

#ifdef _MSC_VER
#pragma warning(disable : 4464)
#endif // _MSC_VER

#include "../inc/azure.hpp"
#include "../inc/credentials.hpp"

#include <stdlib.h>

#include "../inc/_internal/cfg.hpp"

namespace azure
{
namespace core
{

int main()
{
  identity::client_secret_credential csc("tenant_id", "client_id", "SECRET");
  identity::_internal::set_scopes(csc, "scopeA;scopeB");
  return 0;
}

} // namespace core
} // namespace azure
