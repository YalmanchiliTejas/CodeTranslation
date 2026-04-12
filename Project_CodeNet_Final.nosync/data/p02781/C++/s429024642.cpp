#if 1
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <array>
#include <deque>
#include <algorithm>
#include <utility>
#include <cstdint>
#include <functional>
#include <iomanip>
#include <numeric>
#include <assert.h>
#include <bitset>
#include <list>
#include <cmath>

auto& in = std::cin;
auto& out = std::cout;
#define all_range(C) std::begin(C), std::end(C)
const double PI = 3.141592653589793238462643383279502884197169399375105820974944;


template<typename T, typename U>
std::enable_if_t<std::rank<T>::value == 0> fill_all(T& arr, const U& v) {
    arr = v;
}
template<typename ARR, typename U>
std::enable_if_t<std::rank<ARR>::value != 0> fill_all(ARR& arr, const U& v) {
    for (auto& i : arr) {
        fill_all(i, v);
    }
}

std::string S;
int64_t dp[200][10][2];
int func(int i, int k, int can_over = false) {
    if (k < 0) { return 0; }
    if (i == S.size()) {
        return k == 0 ? 1 : 0;
    }
    auto& memo = dp[i][k][can_over?1:0];
    if (memo != -1) {
        return memo;
    }
    int si = can_over?10:(S[i] - '0');

    memo = func(i+1,k,0 < si);//v=0
    for (int v = 1; v <= si && v < 10; v++)
    {
        memo += func(i + 1, k-1, v < si);
    }
    return memo;
}

int main()
{
    using std::endl;
    in.sync_with_stdio(false);
    out.sync_with_stdio(false);
    in.tie(nullptr);
    out.tie(nullptr);

    int K;
    in >> S >> K;
    fill_all(dp, -1);
    out << func(0, K) << endl;

    return 0;
}
#endif
