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

ll nxt_pos[45][100010], nxt_sum[45][100010];

int main() {
    ll N, X, M; scanf("%lld%lld%lld", &N, &X, &M);

    int B = 40;
    for(int i=0; i<M; i++) {
        nxt_pos[0][i] = 1LL*i*i%M;
        nxt_sum[0][i] = i;
    }
    for(int k=1; k<=B; k++) {
        for(int i=0; i<M; i++) {
            nxt_pos[k][i] = nxt_pos[k-1][ nxt_pos[k-1][i] ];
            nxt_sum[k][i] = nxt_sum[k-1][i] + nxt_sum[k-1][ nxt_pos[k-1][i] ];
        }
    }

    ll ans = 0;
    for(int k=0; k<=B; k++) {
        if(!(N >> k & 1)) continue;
        ans += nxt_sum[k][X];
        X = nxt_pos[k][X];
    }
    cout << ans << endl;
    return 0;
}
