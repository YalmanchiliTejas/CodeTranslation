// #define _GLIBCXX_DEBUG // for STL debug (optional)
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <cfloat>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <fstream>
#include <functional>
#include <bitset>
using namespace std;
using ll = long long int;
using int64 = long long int;
 
template<typename T> void chmax(T &a, T b) {a = max(a, b);}
template<typename T> void chmin(T &a, T b) {a = min(a, b);}
template<typename T> void chadd(T &a, T b) {a = a + b;}
 
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
const int INF = 1LL << 29;
const ll LONGINF = 1LL << 60;
const ll MOD = 1000000007LL;
 
int main() {
    ll N, X, M; scanf("%lld%lld%lld", &N, &X, &M);

    vector<ll> mod(M);
    ll x = X, ans = 0;
    for(ll i=0; i<N; i++) {
        // すでに訪れたことがある
        if(mod[x]) {
            vector<ll> rec(1, 0);
            ll y = x;
            while(true) {
                ll s = (rec.back());
                rec.emplace_back(s + y);
                y = y*y % M;
                if(y == x) break;
            }
            ll p = rec.size() - 1;
            ll m = (N-i) % p, d = (N-i) / p;
            ans += d*rec.back() + rec[m];
            break;
        }
        else {
            mod[x] = true;
            ans += x;
            x = x*x % M;
        }
    }
    cout << ans << endl;
    return 0;
}
