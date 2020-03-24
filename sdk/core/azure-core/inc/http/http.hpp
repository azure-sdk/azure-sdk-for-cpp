// Copyright (c) Microsoft Corporation. All rights reserved.
// SPDX-License-Identifier: MIT

#pragma once

#include <string>
#include <vector>

#include <internal/contract.hpp>

using namespace std;

namespace azure
{
namespace core
{
namespace http
{

class Header
{
private:
  string name;
  string value;

public:
  Header(string name, string value)
  {
    this->name = name;
    this->value = value;
  }
  ~Header() {}
  string getName();
  string getValue();
};

class Request
{

private:
  string method;
  string url;
  std::vector<Header> headers;
  string body;

public:
  Request(string httpMethod, string url)
  {
    this->method = httpMethod;
    this->url = url;
  }

  Request(string httpMethod, string url, string body) : Request(httpMethod, url)
  {
    this->body = body;
  }

  ~Request() {}
  string getMethod();
  string getUrl();
  string getBody();
  void addHeader(string name, string value);
};

} // namespace http
} // namespace core
} // namespace azure
