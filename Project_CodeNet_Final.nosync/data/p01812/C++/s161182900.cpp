// テ・ツ淞コテヲツ慊ャテ」ツδ?」ツδウテ」ツδ療」ツδャテ」ツδシテ」ツδ?

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

int N, M, K;
int dp[1<<16], to[1<<16][110];
int v[110][110];
int d[20], dark[110];

signed main() {
    cin >> N >> M >> K;
    memset(dark, -1, sizeof(dark));
    rep(i,0,M) {
        cin >> d[i]; d[i]--;
        dark[ d[i] ] = i;
    }
    rep(i,0,N) rep(j,0,K) cin >> v[i][j], v[i][j]--;

    rep(bit,0,1<<M) rep(i,0,K) {
        int nbit = 0;
        rep(k,0,M) {
            if(bit >> k & 1) {
                if(dark[ v[d[k]][i] ] < 0) continue;
                nbit |= (1 << dark[ v[d[k]][i] ]);
            }
        }
        to[bit][i] = nbit;
    }

    rep(i,0,(1<<M)-1) dp[i] = INF;
    queue<int> q; q.push((1<<M)-1);
    while(!q.empty()) {
        int bit = q.front(); q.pop();
        rep(i,0,K) {
            int nbit = to[bit][i];
            if(dp[nbit] > dp[bit] + 1) {
                dp[nbit] = dp[bit] + 1;
                q.push(nbit);
            }
        }
    }
    cout << dp[0] << endl;
    return 0;
}