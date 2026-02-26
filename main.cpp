#include <iostream>g
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
#include "number-converter.h"

int main() {
	std::string input{};
	std::string inputStr{};
	int inputNum{};
	while (true) {
		std::cout << "What do you want to do? (Hex > Binary, Binary > Hex, Binary > Decimal, Hex > Decimal, Decimal > Binary, Decimal > Hex, q to quit)\n";
		std::getline(std::cin, input);

		if (input == "q" || input == "Q") {
			break;
		}
		else if (input == "Hex > Binary") {
			std::cout << "Enter the hexadecimal number without spaces: ";
			std::cin >> inputStr;
			std::cout << getBinaryFromHex(inputStr) << '\n';
		}
		else if (input == "Binary > Hex") {
			std::cout << "Enter the binary number in groups of four digits (it's okay to add zeros on the the front): ";
			std::getline(std::cin, inputStr);
			std::cout << getHexFromBinary(inputStr) << '\n';
		}
		else if (input == "Binary > Decimal") {
			std::cout << "Enter the binary number in groups of four digits (it's okay to add zeros on the the front): ";
			std::getline(std::cin, inputStr);
			std::cout << getDecimalFromBinary(inputStr) << '\n';
		}
		else if (input == "Hex > Decimal") {
			std::cout << "Enter the hexadecimal number without spaces: ";
			std::cin >> inputStr;
			std::cout << getDecimalFromHex(inputStr) << '\n';
		}
		else if (input == "Decimal > Binary") {
			std::cout << "Enter a whole decimal number: ";
			std::getline(std::cin, inputStr);
			std::cout << getBinaryFromDecimal(std::stoi(inputStr)) << '\n';
		}
		else if (input == "Decimal > Hex") {
			std::cout << "Enter a whole decimal number: ";
			std::getline(std::cin, inputStr);
			std::cout << getHexFromDecimal(std::stoi(inputStr)) << '\n';
		}
	}
}