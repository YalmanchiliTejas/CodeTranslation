#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <bitset>
#include <array>
#include <vector>
#include <queue>
#include <set>
#include <cmath> // 変数名にy1が使えなくなるかも…。
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <limits>
#include <functional>
#include <string>

typedef __int128_t int128_t;
std::istream &operator>>(std::istream& input, int128_t& value) { // int128_tの入力。入力が64bitに収まる前提。
    int64_t tmp; input >> tmp; value = tmp;
    return input;
}
std::ostream &operator<<(std::ostream& output, const int128_t value) { // int128_tの出力。出力が64bitに収まる前提。
    output << (int64_t)value;
    return output;
}

int128_t imax(const int128_t a, const int128_t b) { return std::max(a, b); } // std::max, std::min は型が違うとエラーになるため、ラッパーを作る。
int128_t imin(const int128_t a, const int128_t b) { return std::min(a, b); }

#define rep(i, begin, end) for(int64_t i = ((int64_t)begin); i <= ((int64_t)end); i++) // (int64_t)end としておくと、end = v.size() - 2 みたいな入力で、v.size()が1でも正常(end = -1になる）に挙動する。
#define rev(i, begin, end) for(int64_t i = ((int64_t)begin); ((int64_t)end) <= i; i--)

#define input1(begin, end, v1) v1.resize((end)+1); for (int i = (begin); i <= (end); i++) { std::cin >> v1[i]; }
#define input2(begin, end, v1, v2) v1.resize((end)+1); v2.resize((end)+1); for (int i = (begin); i <= (end); i++) { std::cin >> v1[i] >> v2[i]; } 
#define input3(begin, end, v1, v2, v3) v1.resize((end)+1); v2.resize((end)+1); v3.resize((end)+1); for (int i = (begin); i <= (end); i++) { std::cin >> v1[i] >> v2[i] >> v3[i]; }
#define input4(begin, end, v1, v2, v3, v4) v1.resize((end)+1); v2.resize((end)+1); v3.resize((end)+1); v4.resize((end)+1); for (int i = (begin); i <= (end); i++) { std::cin >> v1[i] >> v2[i] >> v3[i] >> v4[i]; }

std::vector<int> irange(const int begin, const int end) {
    std::vector<int> ret; for (int i = begin; i <= end; i++) { ret.push_back(i); }
    return ret;
}

template <typename T>
void printvec(const std::vector<T>& vec) {
    for (int i = 0; i < vec.size(); i++) { std::cout << vec[i] << " "; } std::cout << std::endl;
}

int N;
//int128_t ;
//std::vector<int> ;
std::vector<int128_t> x, y;
//std::string ;
//std::vector<std::string> ;
//double ;
//std::vector<double> ;

//const int MAX_N = ;
//const int MOD = ;
const int128_t INF = std::numeric_limits<int64_t>::max();
using pair = std::pair<int128_t, int>;

int main(int argc, char **argv) {
    std::cin >> N;

    input2(1, N, x, y);

    if (N == 1) {
        std::cout << 0 << std::endl;
        return 0;
    }

    int128_t maxmax = 0;
    int128_t minmin = INF;
    int128_t minmax = 0;
    int128_t maxmin = INF;

    std::vector<pair> vec;

    rep (i, 1, N) {
        maxmax = imax(maxmax, imax(x[i], y[i]));
        minmin = imin(minmin, imin(x[i], y[i]));
        minmax = imax(minmax, imin(x[i], y[i]));
        maxmin = imin(maxmin, imax(x[i], y[i]));
        vec.push_back(pair({x[i], i}));
        vec.push_back(pair({y[i], i}));
    }

    int128_t ret = (maxmax - maxmin) * (minmax - minmin);

    std::sort(vec.begin(), vec.end());

    std::vector<int> cnt; cnt.resize(N + 1, 0);
    int cnt_sum = 0;
    int end = 0;
    rep (i, 1, N*2 - 2) {
        while (cnt_sum < N && end < N*2 - 1) {
            end++;
            if (end == N*2 - 1) { break; }

            if (cnt[vec[end].second] == 0) {
                cnt_sum++;
            }
            cnt[vec[end].second]++;
        }
        if (cnt_sum == N && end < N*2 - 1) {
            ret = imin(ret, (maxmax - minmin) * (vec[end].first - vec[i].first));
        }

        if (cnt[vec[i].second] == 1) {
            cnt_sum--;
        }
        cnt[vec[i].second]--;
    }

    std::cout << ret << std::endl;

    
    
    return 0;
}