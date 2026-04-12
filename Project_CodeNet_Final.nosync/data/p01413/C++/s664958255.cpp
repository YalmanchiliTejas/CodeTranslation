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

#define debug(...) fprintf(stderr, __VA_ARGS__)
#define int long long int
 
template<typename T> void chmax(T &a, T b) {a = max(a, b);}
template<typename T> void chmin(T &a, T b) {a = min(a, b);}
template<typename T> void chadd(T &a, T b) {a = a + b;}
 
typedef pair<int, int> pii;
typedef long long ll;
 
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
const int INF = 1LL << 60;
const ll MOD = 1000000007LL;

int N, M, W, T;
int dp[1 << 8][8], rec[1 << 7][10010][8], best[1 << 7][8], tmr[1 << 7][8];
int res[10010];

map<string, int> item_map;
string S[10], R[10][10];
int V[10], P[10], L[10], X[10], Y[10], Q[10][10], idR[10][10], idS[10];

signed main() {
    cin >> N >> M >> W >> T;
    for(int i=0; i<M; i++) {
        cin >> S[i] >> V[i] >> P[i];
        item_map[ S[i] ] = i;
    }
    for(int i=0; i<N; i++) {
        cin >> L[i] >> X[i] >> Y[i];
        for(int k=0; k<L[i]; k++) {
            cin >> R[i][k] >> Q[i][k];
        }
    }

    /*
    int id = 0;
    for(auto &e : item_map) e.second = id++;
    for(int i=0; i<M; i++) idS[i] = item_map[ S[i] ];
    */
    for(int i=0; i<N; i++) {
        for(int j=0; j<L[i]; j++) {
            idR[i][j] = item_map[ R[i][j] ];
        }
    }

    N++;
    fill(dp[0], dp[1 << N], INF);
    dp[0][N-1] = 0;
    for(int bit=0; bit<(1<<N); bit++) {
        for(int i=0; i<N; i++) {
            if(dp[bit][i] == INF) continue;
            // fprintf(stderr, "dp[%lld][%lld] = %lld\n", bit, i, dp[bit][i]);
            for(int k=0; k<N; k++) {
                if(i == k or (bit >> k & 1)) continue;
                int nbit = bit | (1 << k);
                int dis = abs(X[i] - X[k]) + abs(Y[i] - Y[k]);
                chmin(dp[nbit][k], dp[bit][i] + dis);
            }
        }
    }

    fill(rec[0][0], rec[1 << (N-1)][0], -1);
    rec[0][0][N-1] = 0;
    for(int bit=0; bit<(1<<(N-1)); bit++) {
        for(int i=0; i<N; i++) {
            for(int k=0; k<N-1; k++) {
                if(i == k or (bit >> k & 1)) continue;
                int nbit = bit | (1 << k);
                for(int w=0; w<=W; w++) {
                    if(rec[bit][w][i] < 0) continue;
                    // fprintf(stderr, "rec[%lld][%lld][%lld] = %lld\n", bit, w, i, rec[bit][w][i]);
                    chmax(rec[nbit][w][k], rec[bit][w][i]);
                }

                for(int x=0; x<L[k]; x++) {
                    int earn = P[ idR[k][x] ] - Q[k][x];
                    int weight = V[ idR[k][x] ];

                    // if(nbit == 1) // fprintf(stderr, "earn = %lld, weight = %lld\n", earn, weight);
                    for(int w=0; w<=W-weight; w++) {
                        if(rec[nbit][w][k] < 0) continue;
                        chmax(rec[nbit][w+weight][k], rec[nbit][w][k] + earn);
                    }
                }
            }
        }
    }

    for(int bit=0; bit<(1<<(N-1)); bit++) {
        for(int i=0; i<N-1; i++) {
            int ma = 0;
            for(int j=0; j<=W; j++) ma = max(ma, rec[bit][j][i]);
            best[bit][i] = ma;
            tmr[bit][i] = dp[bit][i] + abs(X[i]) + abs(Y[i]);
            if(tmr[bit][i] >= INF) continue;
            // fprintf(stderr, "best[%lld][%lld] = %lld, tmr = %lld\n", bit, i, best[bit][i], tmr[bit][i]);
        }
    }

    for(int i=0; i<=T; i++) {
        for(int bit=0; bit<(1<<(N-1)); bit++) {
            for(int k=0; k<N-1; k++) {
                if(i + tmr[bit][k] > T) continue;
                chmax(res[i + tmr[bit][k]], res[i] + best[bit][k]);
            }
        }
    }
    cout << *max_element(res, res + T + 1) << endl;
    return 0;
}

