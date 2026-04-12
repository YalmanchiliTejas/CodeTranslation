#define _USE_MATH_DEFINES
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

const int MOD = 1000000007; 
const int INF = 1000000000; //1e9
const int NIL = -1;
const long long LINF = 1000000000000000000; // 1e18
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
    std::string K; std::cin >> K;
    int N(K.length()), D; std::cin >> D;
    //dpn[i][j] := 上からi桁(0o)でmodD = j の数(n:0 小さい確定)
    std::vector<std::vector<int>> dp0(N+1, std::vector<int>(D, 0));
    std::vector<std::vector<int>> dp1(N+1, std::vector<int>(D, 0));
    dp1[0][0] = 1;
    for(int i(0); i < N; ++i){
        int n(K[i]-'0');
        for(int j(0); j < D; ++j){
            for(int k(0); k < 10; ++k){
                dp0[i+1][(j+k)%D] = (dp0[i+1][(j+k)%D] + dp0[i][j]) % MOD;
            }
            for(int k(0); k < n; ++k){
                dp0[i+1][(j+k)%D] = (dp0[i+1][(j+k)%D] + dp1[i][j]) % MOD;
            }
            dp1[i+1][(j+n)%D] = (dp1[i+1][(j+n)%D] + dp1[i][j]) % MOD;
        }
    }
    std::cout << (dp0[N][0] + dp1[N][0] - 1 + MOD) % MOD << std::endl;
    return 0;
}
