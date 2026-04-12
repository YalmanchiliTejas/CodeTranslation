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

int dpc[510][2][2], dpn[510][2][2];

int solve(string &s, string &t, int inc_equal) {
    int N = s.size(), M = t.size();
    fill(dpc[0][0], dpc[M+1][0], 0LL);

    int res = 0;
    dpc[0][0][0] = 1;
    for(int i=0; i<=N; i++) {
        for(int j=0; j<=M; j++) {
            for(int f=0; f<2; f++) {
                for(int l=0; l<2; l++) {
                    // fprintf(stderr, "dp[%lld][%lld][%lld][%lld] = %lld\n", i, j, f, l, dpc[j][f][l]);
                    if(i == N) continue;
                    
                    int lim = f ? 9 : s[i] - '0';
                    for(int x=0; x<=lim ;x++) {
                        int nl = l || x > 0;
                        if(j < M) {
                            int c = (t[j] - '0') == x;
                            if(c and nl) (dpn[j+1][f || x < lim][nl] += dpc[j][f][l]) %= MOD;
                            if(!j) (dpn[j  ][f || x < lim][nl] += dpc[j][f][l]) %= MOD;
                        }
                        if(j == M) {
                            (dpn[j][f || x < lim][nl] += dpc[j][f][l]) %= MOD;
                        }
                    }
                    dpc[j][f][l] = 0;
                }
            }
        }
        if(i < N) swap(dpc, dpn);
    }
    (res += dpc[M][1][1]) %= MOD;
    if(inc_equal) (res += dpc[M][0][1]) %= MOD;
    if(t == "0" and !(s == "0" and !inc_equal)) (res += 1) %= MOD;
    // fprintf(stderr, "res = %lld\n", res);
    return res;
}

signed main() {
    string A, B, C; cin >> A >> B >> C;
    int ans = (solve(B, C, 1) - solve(A, C, 0) + MOD) % MOD;
    cout << ans << endl;
    return 0;
}

