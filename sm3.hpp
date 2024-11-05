#pragma once

#include <vector>
#include <bitset>
#include <string>
using namespace std;

class SM3 {
private:
    // 初始化向量(具体值见SM3构造函数)
    bitset<256> IV;
    // 常量T(具体值见SM3构造函数)
    vector<bitset<32>> T;
    // 消息扩展阶段用到的W和W`
    vector<bitset<32>> W = vector<bitset<32>>(68, 0x00);
    vector<bitset<32>> Wp = vector<bitset<32>>(64, 0x00);
    // 消息填充
    vector<bitset<8>> padding(string M);
    // 迭代压缩
    bitset<256> compression(vector<bitset<8>> m);
    // 压缩函数
    bitset<256> CF(bitset<256> vi, bitset<512> bi);
    // 消息扩展
    void extension(bitset<512> bi);
public:
    SM3();
    bitset<256> hash(string str);
};