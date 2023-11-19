
# String Class

## Overview
This String class is a custom implementation in C++ designed to mimic and extend the functionalities of the standard string library. It offers a more controlled environment for handling strings, with added flexibility and functionality.

## Features

- Dynamic memory management for efficient storage and manipulation.
- Support for common string operations like `push_back`, `pop_back`, `clear`, and `empty`.
- Capacity and size management functions.
- Overloaded operators for equality, comparison, addition, stream insertion, and extraction.
- Custom methods for finding substrings, both from the beginning (`find`) and end (`rfind`) of the string.
- Method to create a substring (`substr`) from the string.

## Usage

### Creating and Modifying Strings
```cpp
String str1("Hello");
String str2 = 'A';
str1.push_back('B');
str2 += "BC";
```

### Comparing Strings
```cpp
bool areEqual = (str1 == str2);
bool notEqual = (str1 != str2);
```

### Concatenating Strings
```cpp
String str3 = str1 + str2;
str3 += 'D';
```

### Finding Substrings
```cpp
size_t foundIndex = str1.find("lo");
size_t rfoundIndex = str1.rfind("He");
```

### Stream Operations
```cpp
std::cout << str1 << std::endl;
std::cin >> str2;
```

## Special Notes
- The class handles its own memory, dynamically allocating and deallocating as necessary. 
- It is designed to be as intuitive as possible, mirroring the standard `std::string` in many ways but providing additional control.
- Be aware of the capacity and size properties, especially in performance-critical applications.

## Installation
- Include the `String` class definition in your C++ project.
- Compile your project with a C++11 (or later) compatible compiler.
