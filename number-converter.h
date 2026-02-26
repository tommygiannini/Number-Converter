#ifndef NUMBER_CONVERTER
#define NUMBER_CONVERTER

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>

std::string getBinary(char n);
std::string getHex(std::string segement);
std::string getBinaryFromHex(std::string hex);
std::string getHexFromBinary(std::string binary);
int getDecimalFromBinary(const std::string& binary);
int getDecimalFromHex(std::string Hex);
std::string getBinaryFromDecimal(int decimal);
std::string getHexFromDecimal(int decimal);

#endif