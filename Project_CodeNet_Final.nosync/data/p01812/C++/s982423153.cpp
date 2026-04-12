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
const int EXPN = 1 << 16;
int d[20], v[110][110];
bool dp[EXPN-1][30];
int dark[110];
int to[EXPN-1][110];
int dist[EXPN-1];
bool visited[EXPN-1];

signed main() {
    memset(dp, false, sizeof(dp));
    memset(dark, -1, sizeof(dark));
    memset(visited, false, sizeof(visited));
    cin >> N >> M >> K;
    rep(i,0,M) {
        cin >> d[i];
        d[i]--;
        // i ???????????????????????????????????? (????????´?????????????????????????????????)
        dark[ d[i] ] = i;
    }
    rep(i,0,N) rep(j,0,K) {
        cin >> v[i][j];
        v[i][j]--;
        // ???????????????????????°??????????????\??????
        if(dark[ v[i][j] ] == -1) v[i][j] = -1;
        else v[i][j] = dark[ v[i][j] ];
    }

    rep(j,0,K) {
        rep(bit,0,1<<M) {
            int nbit = 0;
            rep(i,0,M) {
                if(bit >> i & 1) {
                    if(v[d[i]][j] < 0) continue;
                    int val = 1 << v[d[i]][j];
                    nbit |= val;
                }
            }
            to[bit][j] = nbit;
        }
    }
    
    rep(i,0,1<<M) dist[i] = INF;
    dist[(1<<M)-1] = 0;
    priority_queue< int, vector<int>, greater<int> > q;
    q.push((1<<M)-1);
    while(!q.empty()) {
        int t = q.top(); q.pop();
        rep(i,0,K) {
            int nx = to[t][i];
            if(dist[nx] > dist[t] + 1) {
                dist[nx] = dist[t] + 1;
                q.push(nx);
            }
        }
    }
    cout << dist[0] << endl;
    return 0;
}