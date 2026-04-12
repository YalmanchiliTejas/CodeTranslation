#define _USE_MATH_DEFIMES
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <clocale>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

const int MOD = 1'000'000'007;
const int INF = 1'000'000'000; //1e9
const int NIL = -1;
const long long LINF = 1'000'000'000'000'000'000; // 1e18
const long double EPS = 1E-10;

template<class T, class S> inline bool chmax(T &a, const S &b){
    if(a < b){
        a = b; return true;
    }
    return false;
}
template<class T, class S> inline bool chmin(T &a, const S &b){
    if(b < a){
        a = b; return true;
    }
    return false;
}








int main(){
    int N; std::cin >> N;
    std::vector<int> A(N);
    std::vector<long long> S(N+1);
    for(int i(0); i < N; ++i){
        std::cin >> A[i];
        S[i+1] = (S[i] + A[i]) % MOD;
    }
    long long ans(0);
    for(int i(0), i_len(N-1); i < i_len; ++i){
        (ans += A[i] * (S[N] - S[i+1])) %= MOD;
        if(ans < 0) ans += MOD;
    }
    std::cout << ans << std::endl;
    return 0;
}
