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
    int N, M, K; cin >> N >> M >> K;
    vector<int> D(M);
    for(int i=0; i<M; i++) cin >> D[i], D[i]--;

    vector<int> id(N, -1);
    for(int i=0; i<M; i++) id[ D[i] ] = i;
    
    vector< vector<int> > to(N, vector<int>(K));
    for(int i=0; i<N; i++) {
        for(int j=0; j<K; j++) {
            cin >> to[i][j]; to[i][j]--;
        }
    }

    vector<int> dp(1<<M, INF);
    dp[(1<<M)-1] = 0;
    queue< pair<int, int> > que;
    que.emplace((1<<M)-1, 0);

    while(que.size()) {
        int bit, cost; tie(bit, cost) = que.front(); que.pop();
        if(dp[bit] < cost) continue;
        for(int i=0; i<K; i++) {
            int nbit = 0;
            for(int x=0; x<M; x++) {
                if(!(bit >> x & 1)) continue;
                int p = to[ D[x] ][i];
                if(id[p] >= 0) nbit |= (1 << id[p]);
            }
            if(dp[nbit] > dp[bit] + 1) {
                dp[nbit] = dp[bit] + 1;
                que.emplace(nbit, dp[nbit]);
            }
        }
    }
    printf("%d\n", dp[0]);
    return 0;
}

