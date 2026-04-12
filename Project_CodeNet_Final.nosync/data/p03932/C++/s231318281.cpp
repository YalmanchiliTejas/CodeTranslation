#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
#include <complex>
#include <array>
#include <functional>
using namespace std;
 
#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()
 
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<double> VD;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VD> VVD;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

template<typename T> void chmin(T &a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T &a, T b) { if (a < b) a = b; }

int in() { int x; scanf("%d", &x); return x; }
ll lin() { ll x; scanf("%lld", &x); return x; }

const int N = 405;
int dp[N][N][N];

int main() {
    int h, w;
    cin >> h >> w;
    VVI a(h, VI(w));
    REP(i,h) REP(j,w){
        a[i][j] = in();
    }
    dp[1][1][0] = a[0][0] + a[1][0] + a[0][1];
    FOR(i,1,h+w-3) REP(xi,h) REP(yi,xi){
        int xj = i - xi;
        int yj = i - yi;
        if (xj < 0 || xj >= w) continue;
        if (yj < 0 || yj >= w) continue;
        if (xi < h - 1 && yi < h - 1){
            chmax(dp[i + 1][xi + 1][yi + 1], dp[i][xi][yi] + a[xi + 1][xj] + a[yi + 1][yj]);
        }
        if (xi < h - 1 && yj < w - 1){
            chmax(dp[i + 1][xi + 1][yi], dp[i][xi][yi] + a[xi + 1][xj] + a[yi][yj + 1]);
        }
        if (xj < w - 1 && yi < h - 1 && xi > yi + 1){
            chmax(dp[i + 1][xi][yi + 1], dp[i][xi][yi] + a[xi][xj + 1] + a[yi + 1][yj]);
        }
        if (xj < w - 1 && yj < w - 1){
            chmax(dp[i + 1][xi][yi], dp[i][xi][yi] + a[xi][xj + 1] + a[yi][yj + 1]);
        }
    }
    int ans = dp[h + w - 3][h - 1][h - 2] + a[h - 1][w - 1];
    cout << ans << endl;


    return 0;
}
