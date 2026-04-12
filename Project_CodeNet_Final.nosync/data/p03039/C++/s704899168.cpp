#include <iostream>
#include <cstdio>
#include <sstream>

#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <deque>
#include <queue>
#include <stack>

#include <algorithm>
#include <utility>
#include <numeric>
#include <functional>

#include <chrono>
#include <random>

using namespace std;
using i64 = int_fast64_t;
using ui64 = uint_fast64_t;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<i64>;
using vvl = vector<vl>;
using vd = vector<double>;
using vvd = vector<vd>;
using vb = vector<bool>;
using vvb = vector<vb>;
using pii = pair<int, int>;
using pll = pair<i64, i64>;

//////////////////////////////////////////////////

const i64 mod = 1e9+7LL;

int main(){
    i64 N, M, K;
    cin >> N >> M >> K;
    if(N > M)swap(N, M);
    i64 ret = 0;
    i64 C = 1;
    if(K != 2){
        auto pow = [&](i64 a, i64 r){
            i64 ret = 1LL;
            while(r){
                if(r&1LL)ret = ret * a % mod;
                a = a * a % mod;
                r >>= 1;
            }
            return ret;    
        };
        for(i64 i=1;i<=K-2;i++){
            C = C * (N * M - 1 - i) % mod * pow(i, mod-2) % mod;
        }
    }
    for(i64 s = 1LL;s <= N + M - 1LL;s++){
        for(i64 i = 0LL;i <= min(N, s);i++){
            i64 j = s - i;
            i64 n = max((i64)N - i, (i64)0LL);
            i64 m = max((i64)M - j, (i64)0LL);
            i64 k = n * m % mod;
            if(i!=0 && i!=s)k = k * 2 % mod;
            ret = (ret + k * s % mod) % mod;
        }
    }
    // cerr << C << endl;
    cout << ret * C % mod << endl;
    return 0;
}
