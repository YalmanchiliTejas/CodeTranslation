#ifndef ENV_AC
    #define ENV_AC
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

    using int128_t = __int128_t;
    std::istream &operator>>(std::istream& input, int128_t& value) { // int128_tの入力。入力が64bitに収まる前提。
        int64_t tmp; input >> tmp; value = tmp;
        return input;
    }
    std::ostream &operator<<(std::ostream& output, const int128_t value) { // int128_tの出力。出力が64bitに収まる前提。
        output << (int64_t)value;
        return output;
    }

    namespace std {
        template<> class hash<int128_t>{
            public:
            size_t operator () ( const int128_t &x ) const {
                int64_t INF64 = std::numeric_limits<int64_t>::max();
                int64_t y1 = x / INF64;
                int64_t y2 = x % INF64;
                return hash<int64_t>()(y1) ^ hash<int64_t>()(y2);
            }
        };
    }

    int128_t imax(const int128_t a, const int128_t b) { return std::max(a, b); } // std::max, std::min は型が違うとエラーになるため、ラッパーを作る。
    int128_t imin(const int128_t a, const int128_t b) { return std::min(a, b); }
    int128_t iabs(const int128_t x) { return 0 <= x ? x : -x; }
    int128_t ipow(const int128_t x, const int128_t n) { int128_t ret = 1; for (int i = 0; i < n; i++) { ret *= x; } return ret; }

    #define rep(i, begin, end) for(int64_t i = ((int64_t)begin); i <= ((int64_t)end); i++) // (int64_t)end としておくと、end = v.size() - 2 みたいな入力で、v.size()が1でも正常(end = -1になる）に挙動する。
    #define rev(i, begin, end) for(int64_t i = ((int64_t)begin); ((int64_t)end) <= i; i--) // int128_tにすると、3重ループでコンパイルエラーになったのでint64_tにしておく。

    #define input1(begin, end, v1) v1.resize((end)+1); for (int i = (begin); i <= (end); i++) { std::cin >> v1[i]; }
    #define input2(begin, end, v1, v2) v1.resize((end)+1); v2.resize((end)+1); for (int i = (begin); i <= (end); i++) { std::cin >> v1[i] >> v2[i]; } 
    #define input3(begin, end, v1, v2, v3) v1.resize((end)+1); v2.resize((end)+1); v3.resize((end)+1); for (int i = (begin); i <= (end); i++) { std::cin >> v1[i] >> v2[i] >> v3[i]; }
    #define input4(begin, end, v1, v2, v3, v4) v1.resize((end)+1); v2.resize((end)+1); v3.resize((end)+1); v4.resize((end)+1); for (int i = (begin); i <= (end); i++) { std::cin >> v1[i] >> v2[i] >> v3[i] >> v4[i]; } 
    #define input5(begin, end, v1, v2, v3, v4, v5) v1.resize((end)+1); v2.resize((end)+1); v3.resize((end)+1); v4.resize((end)+1); v5.resize((end)+1); for (int i = (begin); i <= (end); i++) { std::cin >> v1[i] >> v2[i] >> v3[i] >> v4[i] >> v5[i]; }  
    // input_arrayはbegin = 0のときのみ動作確認。Aの要素の型をテンプレートにして関数にしたほうが丁寧かもしれない。
    #define input_array(begin, N, M, A) A.resize((begin)+(N)); for (int i = 0; i < (begin)+(N); i++) { A[i].resize((begin)+(M)); } for (int i = begin; i < (begin)+(N); i++) { for (int j = begin; j < (begin)+(M); j++) { std::cin >> A[i][j]; }}

    std::vector<int> irange(const int begin, const int end) {
        std::vector<int> ret; for (int i = begin; i <= end; i++) { ret.push_back(i); }
        return ret;
    }

    template <typename T>
    std::vector<T> accumulate_vec(const std::vector<T>& vec, const bool reverse = false) {
        std::vector<T> ret; ret.resize(vec.size());
        if (reverse == false) {
            ret[0] = vec[0];
            for (int i = 1; i < ret.size(); i++) {
                ret[i] = ret[i-1] + vec[i];
            }
        } else {
            ret[ret.size()-1] = vec[ret.size()-1];
            for (int i = ret.size() - 2; 0 <= i; i--) {
                ret[i] = ret[i+1] + vec[i];
            }
        }
        return ret;
    }

    template <typename T>
    void printvec(const std::vector<T>& vec) {
        for (int i = 0; i < vec.size(); i++) { std::cout << vec[i] << " "; } std::cout << std::endl;
    }
#endif

//--code begin--

int128_t D;
//std::vector<int128_t> x, y;
//std::vector<std::vector<int128_t>> a;
std::string K;
//std::vector<std::string> a;
//double X;
//std::vector<double> p;

const int128_t MAX_N = 1e4 + 10;
const int128_t MAX_D = 100;
const int128_t MOD = 1e9 + 7;
//const int128_t INF = std::numeric_limits<int64_t>::max();
//const double EPS = 1.0e-15;

int128_t dp[MAX_N][2][MAX_D] = {};


int main(int argc, char **argv) {
    std::cin.tie(0);
   	std::ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(15);

    std::cin >> K;
    std::cin >> D;

    K = "!" + K;
    
    dp[0][0][0] = 1;
    int128_t N = K.size() - 1;

    //std::cout << N << std::endl;

    rep (i, 0, N - 1) {
        int128_t c = K[i+1] - '0';
        rep (j, 0, D - 1) {
            //std::cout << i << " " << j << " " << dp[i][0][j] << " " << dp[i][1][j] << std::endl;
            rep (k, 0, 9) {
                dp[i+1][1][(j+k)%D] += dp[i][1][j];
                dp[i+1][1][(j+k)%D] %= MOD;

                if (k == c) {
                    dp[i+1][0][(j+k)%D] += dp[i][0][j];
                    dp[i+1][0][(j+k)%D] %= MOD; 
                }
                if (k < c) {
                    dp[i+1][1][(j+k)%D] += dp[i][0][j];
                    dp[i+1][1][(j+k)%D] %= MOD; 
                }
            }
        }
    }

    //std::cout << dp[N][1][0] << " " << dp[N][0][0] << std::endl;

    int128_t ret = dp[N][1][0] + dp[N][0][0] - 1;
    std::cout << (ret + MOD) % MOD << std::endl;
    

    return 0;
}