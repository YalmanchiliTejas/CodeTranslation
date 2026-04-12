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

ll dp[110][5][2][2];

int main() {
    string s; cin >> s;
    int N = s.size();
    int K; cin >> K;
    
    const int MAX = 4;
    dp[0][0][0][0] = 1;
    for(int i=0; i<N; i++) {
        for(int j=0; j<=MAX; j++) {
            for(int f=0; f<2; f++) {
                for(int l=0; l<2; l++) {
                    // if(dp[i][j][f][l] != 0) fprintf(stderr, "dp[%d][%d][%d][%d] = %lld\n", i, j, f, l, dp[i][j][f][l]);
                    int lim = f ? 9 : s[i] - '0';
                    for(int x=0; x<=lim; x++) {
                        int nj = min(MAX, j + (x != 0));
                        int nf = f || (x < lim);
                        int nl = l || (x != 0);
                        dp[i+1][nj][nf][nl] += dp[i][j][f][l];
                        chmin(dp[i+1][nj][nf][nl], LONGINF);
                    }
                }
            }
        }
    }

    ll ans = dp[N][K][0][1] + dp[N][K][1][1];
    cout << ans << endl;
    return 0;
}
