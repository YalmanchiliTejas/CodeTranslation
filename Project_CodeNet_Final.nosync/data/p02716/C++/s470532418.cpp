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

const int ofs = 10, lim = 10;
ll dp[200010][25][2];

int main() {
    int N; scanf("%d", &N);
    vector<ll> A(N);
    for(int i=0; i<N; i++) scanf("%lld", &A[i]);

    fill(dp[0][0], dp[N+1][0], -LONGINF);
    dp[0][ofs][0] = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<=2*lim; j++) {
            for(int k=0; k<2; k++) {
                int tj = j - ofs;
                if(!k) {
                    if(abs(tj+1) > lim) continue;
                    int nj = (tj+1) + ofs;
                    chmax(dp[i+1][nj][1], dp[i][j][k] + A[i]);
                }
                {
                    if(abs(tj-1) > lim) continue;
                    int nj = (tj-1) + ofs;
                    chmax(dp[i+1][nj][0], dp[i][j][k]);
                }
            }
        }
    }
    cout << max(dp[N][ofs-(N%2)][0], dp[N][ofs-(N%2)][1]) << endl;
    return 0;
}
