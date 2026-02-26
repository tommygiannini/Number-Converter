#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>

std::string getBinary(char n) {
	switch (n) {
	case '0': return "0000 ";
	case '1': return "0001 ";
	case '2': return "0010 ";
	case '3': return "0011 ";
	case '4': return "0100 ";
	case '5': return "0101 ";
	case '6': return "0110 ";
	case '7': return "0111 ";
	case '8': return "1000 ";
	case '9': return "1001 ";
	case 'A': return "1010 ";
	case 'B': return "1011 ";
	case 'C': return "1100 ";
	case 'D': return "1101 ";
	case 'E': return "1110 ";
	case 'F': return "1111 ";
	default: "Make sure all letters are capitol and you entered a real hexadecimal number";
	}
}

std::string getHex(std::string segement) {
	std::string hex{ "" };
	if (segement == std::string("0000")) {
		hex.append(std::string("0"));
	}
	if (segement == std::string("0001")) {
		hex.append(std::string("1"));
	}
	if (segement == std::string("0010")) {
		hex.append(std::string("2"));
	}
	if (segement == std::string("0011")) {
		hex.append(std::string("3"));
	}
	if (segement == std::string("0100")) {
		hex.append(std::string("4"));
	}
	if (segement == std::string("0101")) {
		hex.append(std::string("5"));
	}
	if (segement == std::string("0110")) {
		hex.append(std::string("6"));
	}
	if (segement == std::string("0111")) {
		hex.append(std::string("7"));
	}
	if (segement == std::string("1000")) {
		hex.append(std::string("8"));
	}
	if (segement == std::string("1001")) {
		hex.append(std::string("9"));
	}
	if (segement == std::string("1010")) {
		hex.append(std::string("A"));
	}
	if (segement == std::string("1011")) {
		hex.append(std::string("B"));
	}
	if (segement == std::string("1100")) {
		hex.append(std::string("C"));
	}
	if (segement == std::string("1101")) {
		hex.append(std::string("D"));
	}
	if (segement == std::string("1110")) {
		hex.append(std::string("E"));
	}
	if (segement == std::string("1111")) {
		hex.append(std::string("F"));
	}
	return hex;
}

std::string getBinaryFromHex(std::string hex) {
	std::string binary{ "" };
	for (char ch : hex) {
		binary.append(getBinary(ch));
	}
	return binary;
}

std::string getHexFromBinary(std::string binary) {
	std::stringstream binaryStream(binary);
	std::string temp{};
	std::vector<std::string> segements;

	while (binaryStream >> temp) {
		segements.push_back(temp);
	}

	std::string hex{ "" };
	for (std::string segement : segements) {
		hex.append(getHex(segement));
	}
	return hex;
}

int getDecimalFromBinary(const std::string& binary) {
	int decimal = 0;
	for (char c : binary) {
		if (c == ' ') continue;
		if (c == '0') {
			decimal = decimal * 2;
		}
		else if (c == '1') {
			decimal = decimal * 2 + 1;
		}
		else {

		}
	}
	return decimal;
}

int getDecimalFromHex(std::string Hex) {
	std::string binary(getBinaryFromHex(Hex));
	return getDecimalFromBinary(binary);
}

std::string getBinaryFromDecimal(int decimal) {
	if (decimal == 0) return "0000 ";

	// build MSB-first by inserting each new bit at the front
	std::string bits;
	while (decimal > 0) {
		char bit = char('0' + (decimal % 2));
		bits.insert(bits.begin(), bit); // prepend bit so string becomes MSB..LSB
		decimal /= 2;
	}

	// pad to a multiple of 4 bits
	std::size_t rem = bits.size() % 4;
	if (rem != 0) {
		bits.insert(0, 4 - rem, '0');
	}

	// group into 4-bit segments with a space after each group (matches getBinary output)
	std::string grouped;
	grouped.reserve(bits.size() + bits.size() / 4);
	for (std::size_t i = 0; i < bits.size(); i += 4) {
		grouped.append(bits.substr(i, 4));
		grouped.push_back(' ');
	}

	return grouped;
}

std::string getHexFromDecimal(int decimal) {
	std::string binary{ getBinaryFromDecimal(decimal) };
	return getHexFromBinary(binary);
}
