// Copyright (c) Microsoft Corporation. All rights reserved.
// SPDX-License-Identifier: MIT

#ifndef _az_CORE_IDENTITY_CREDENTIALS_HPP
#define _az_CORE_IDENTITY_CREDENTIALS_HPP

#include <chrono>
#include <string>

#include "_internal/prefix.hpp"

namespace azure
{

namespace identity
{

class credential;

namespace _internal
{
void set_scopes(credential& credential, std::string const& scopes);
} // namespace _internal

class credential
{
  friend void _internal::set_scopes(credential&, std::string const&);

public:
  virtual ~credential() noexcept {};

protected:
  credential() = default;

private:
  credential(credential const&) = delete;
  void operator=(credential const&) = delete;

  virtual void set_scopes(std::string const&) {}
};

 namespace _internal
{

 inline void set_scopes(credential& credential, std::string const& scopes)
{
  credential.set_scopes(scopes);
}

} // namespace _internal

class token_credential : public credential
{
private:
  std::string token_;
  std::string scopes_;
  std::chrono::steady_clock expires_at_;

  token_credential(token_credential const&) = delete;
  void operator=(token_credential const&) = delete;

  virtual void set_scopes(std::string const& scopes) override { scopes_ = scopes; }

public:
  virtual ~token_credential() noexcept {}

protected:
  token_credential() = default;
};

class client_secret_credential : public token_credential
{
private:
  std::string tenant_id_;
  std::string client_id_;
  std::string client_secret_;

  client_secret_credential(client_secret_credential const&) = delete;
  void operator=(client_secret_credential const&) = delete;

public:
  // client_secret_credential() = default;

  client_secret_credential(
      std::string const& tenant_id,
      std::string const& client_id,
      std::string const& client_secret)
      : tenant_id_(tenant_id), client_id_(client_id), client_secret_(client_secret)
  {
  }

  virtual ~client_secret_credential() noexcept override = default;
};

} // namespace identity

} // namespace azure

#include "_internal/suffix.hpp"

#endif // _az_CORE_IDENTITY_CREDENTIALS_HPP
