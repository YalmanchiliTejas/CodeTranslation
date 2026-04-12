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
const ll INF = 1001001001001001LL;
const ll MOD = 1000000007LL;

int dp[10010][110][2];

signed main() {
    string s; cin >> s;
    int D; cin >> D;

    int N = s.length();
    dp[0][0][0] = 1;
    for(int i=0; i<N; i++) {
        for(int k=0; k<D; k++) {
            for(int f=0; f<2; f++) {
                int lim = f ? 9 : s[i] - '0';
                for(int x=0; x<=lim; x++) {
                    int nk = (k + x) % D;
                    int nf = f || (x < lim);
                    (dp[i+1][nk][nf] += dp[i][k][f]) %= MOD;
                }
            }
        }
    }

    cout << (dp[N][0][0] + dp[N][0][1] - 1 + MOD) % MOD << endl;
    return 0;
}
