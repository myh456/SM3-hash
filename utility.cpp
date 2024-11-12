// 工具函数
#include <bitset>

template <size_t N>
std::bitset<N> operator+(const std::bitset<N>& lhs, const std::bitset<N>& rhs) {
    std::bitset<N> result;
    bool carry = false;  // 进位标志

    for (size_t i = 0; i < N; ++i) {
        bool bit1 = lhs[i];  // 左操作数当前位
        bool bit2 = rhs[i];  // 右操作数当前位

        // 按位加法：当前位的和加上进位
        bool sum = bit1 ^ bit2 ^ carry;  // 当前位的和
        carry = (bit1 && bit2) || (carry && (bit1 ^ bit2));  // 计算进位

        result[i] = sum;  // 保存当前位的结果
    }

    return result;
}