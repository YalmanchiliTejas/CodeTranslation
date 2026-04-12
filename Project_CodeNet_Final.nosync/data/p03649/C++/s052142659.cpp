// 基本テンプレート

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
#include <functional>
using namespace std;

#define rep(i,a,n) for(int (i)=(a); (i)<(n); (i)++)
#define repq(i,a,n) for(int (i)=(a); (i)<=(n); (i)++)
#define repr(i,a,n) for(int (i)=(a); (i)>=(n); (i)--)
#define int long long int

template<typename T> void chmax(T &a, T b) {a = max(a, b);}
template<typename T> void chmin(T &a, T b) {a = min(a, b);}
template<typename T> void chadd(T &a, T b) {a = a + b;}

typedef pair<int, int> pii;
typedef long long ll;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
constexpr ll INF = 1001001001001001LL;
constexpr ll MOD = 1000000007LL;
constexpr ll BIN = (ll)1e16;

int N, a[60];

signed main() {
    /*
    random_device rnd;
    mt19937 rand_src(rnd());

    N = rand_src() % 50 + 1;
    rep(i,0,N) {
        a[i] = rand_src() % BIN + 1001;
        printf("show(%lld) = %lld\n", i, a[i]);
    }
    */

    
    cin >> N;
    rep(i,0,N) cin >> a[i];
    
    int ans = 0;
    while(1) {
        rep(i,0,N) {
            if(a[i] < N) continue;
            int diff = a[i] - (N-1);
            int cnt = (diff - 1) / N + 1;
            ans += cnt;
            a[i] -= N * cnt;
            rep(j,0,N) {
                if(i != j) a[j] += cnt;
            }
        }
        bool ok = true;
        rep(i,0,N) {
            if(a[i] >= N) ok = false;
        }
        if(ok) break;
    }
    cout << ans << endl;
    return 0;
}