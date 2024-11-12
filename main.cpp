#include "sm3.hpp"

#include <iostream>
#include <sstream>
#include <iomanip>

string bitsetToHex(bitset<256> bitset) {
    stringstream ss;
    for (int i = 0; i < 256; i += 4) {
        std::bitset<4> nibble = ((bitset >> i) & std::bitset<256>(0xF)).to_ulong();
        ss << std::hex << std::setw(1) << std::setfill('0') << nibble.to_ulong();
    }
    return ss.str();
}

int main(int argc, char const* argv[]) {
    SM3 sm3 = SM3();
    cout << bitsetToHex(sm3.hash("01")) << endl;
    return 0;
}
