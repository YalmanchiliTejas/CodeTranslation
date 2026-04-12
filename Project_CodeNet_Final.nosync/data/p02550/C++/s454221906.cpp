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
    long long N, X, M; std::cin >> N >> X >> M;
    long long ans(0);
    std::vector<long long> a(1);
    std::map<long long, int> mp;
    for(long long i(1); i <= N; ++i){
        ans += X;
        a.emplace_back(ans);
        if(mp[X]){
            int lp(i - mp[X]);
            long long e(ans - a[mp[X]]);
            ans += ((N - i) / lp) * e;
            ans += a[(N - i) % lp + mp[X]] - a[mp[X]];
            std::cout << ans << std::endl;
            return 0;
        }
        mp[X] = i;
        X = X*X % M;
    }
    std::cout << ans << std::endl;
    return 0;
}
