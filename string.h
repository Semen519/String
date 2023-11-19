#include <algorithm>
#include <cstring>
#include <iostream>

class String {
 private:
  char* my_str = nullptr;
  size_t sz = 0;
  size_t cap = 0;

  void allocation(size_t new_cap) {
    cap = new_cap;
    char* copy;
    copy = new char[cap + 1];
    memcpy(copy, my_str, sz);
    std::swap(copy, my_str);
    delete[] copy;
  }

  void swap(String& str) {
    std::swap(my_str, str.my_str);
    std::swap(sz, str.sz);
    std::swap(cap, str.cap);
  }

 public:

  String() : my_str(new char[1]), sz(0), cap(0) {
    my_str[0] = '\0';
  }

  String(size_t n, char c) : my_str(new char[n + 1]), sz(n), cap(n) {
    memset(my_str, c, n);
    my_str[n] = '\0';
  }

  String(const char* str) : my_str(new char[strlen(str) + 1]), sz(strlen(str)), cap(strlen(str)) {
    memcpy(my_str, str, sz);
    my_str[sz] = '\0';
  }

  String (const String& str) : String(str.sz, '\0') {
    memcpy(my_str, str.my_str, str.sz + 1);
  }

  String& operator=(String str) {
    swap(str);
    return *this;
  }

  char& operator[](size_t index) {
    return my_str[index];
  }

  const char& operator[](size_t index) const {
    return my_str[index];
  }

  size_t length() const {
    return sz;
  }

  size_t size() const {
    return sz;
  }

  size_t capacity() const {
    return cap;
  }

  void push_back(char c) {
    if (sz == cap) {
      allocation(2 * cap + 1);
    }
    my_str[sz] = c;
    my_str[sz + 1] = '\0';
    sz++;
  }

  void pop_back() {
    my_str[sz - 1] = '\0';
    sz--;
  }

  char& front() {
    return my_str[0];
  }

  const char& front() const {
    return my_str[0];
  }

  char& back() {
    return my_str[sz - 1];
  }

  const char& back() const{
    return my_str[sz - 1];
  }

  String& operator+=(const char c) {
    push_back(c);
    return *this;
  }

  String& operator+=(const String& str) {
    if (sz + str.sz > cap) {
      allocation(2 * (sz + str.sz) + 1);
    }
    memcpy(my_str + sz, str.my_str, str.sz + 1);
    sz += str.sz;
    return *this;
  }

  size_t find(const String& substr) const {
    for (size_t i = 0; i < sz + 1 - substr.size(); ++i) {
      int rc = memcmp(my_str + i, substr.data(), substr.size());
      if (rc == 0) {
        return i;
      }
    }
    return sz;
  }

  size_t rfind(const String& substr) const {
    for (size_t i = 1 + sz - substr.size(); i > 0; --i) {
      int rc = memcmp(my_str + i - 1, substr.data(), substr.size());
      if (rc == 0) {
        return i - 1;
      }
    }
    return sz;
  }

  String substr(size_t start, size_t count) const {
    String n_str(count, '\0');
    memcpy(n_str.my_str, my_str + start, count);
    return n_str;
  }

  bool empty() const {
    return sz == 0;
  }

  void clear() {
    sz = 0;
    my_str[0] = '\0';
  }

  void shrink_to_fit() {
    if (cap > sz) {
      allocation(sz);
    }
  }

  char* data() {
    return my_str;
  }

  const char* data() const {
    return my_str;
  }

  ~String() {
    delete[] my_str;
  }
};

bool operator==(const String& str1, const String& str2) {
  const int rc = memcmp(str1.data(), str2.data(), str1.size());
  return str1.size() != str2.size() ? false : rc == 0;
}

bool operator!=(const String& str1, const String& str2) {
  return !(str1 == str2);
}

bool operator<(const String& str1, const String& str2) {
  const int rc = memcmp(str1.data(), str2.data(), std::min(str1.size(), str2.size()));
  return rc < 0 || (rc == 0 && str1.size() < str2.size());
}

bool operator>(const String& str1, const String& str2) {
  return str2 < str1;
}

bool operator<=(const String& str1, const String& str2) {
  return !(str2 < str1);
}

bool operator>=(const String& str1, const String& str2) {
  return str2 <= str1;
}

String operator+(const String& str1, const String& str2) {
  String result = str1;
  result += str2;
  return result;
}

String operator+(const String& str, char c) {
  String result = str;
  result += c;
  return result;
}

String operator+(char c, const String& str) {
  char ex[1] = {c};
  String result(ex);
  result += str;
  return result;
}

std::ostream& operator<<(std::ostream& out, const String& str) {
  out << str.data();
  return out;
}

std::istream& operator>>(std::istream& in, String& str) {
  while (std::isspace(in.peek()) != 0 && !in.eof()) {
    in.get();
  }
  while (std::isspace(in.peek()) == 0 && !in.eof()) {
    str.push_back(in.get());
  }
  return in;
}