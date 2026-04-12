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

int main() {
    ll k;
    cin >> k;
    int n = 8;
    VI a;
    REP(j,200) REP(i,n-1) a.push_back(i);
    REP(i,n-1) REP(j,250) a.push_back(i);
    int m = a.size();
    VVL cnt(m + 1, VL(n));
    REP(i,m){
        REP(j,n) cnt[i + 1][j] = cnt[i][j];
        if (a[i] == 0) cnt[i + 1][0]++;
        else cnt[i + 1][a[i]] += cnt[i][a[i] - 1];
    }
    // REP(i,m) cout << cnt[i][n - 2] << " ";
    // cout << endl;
    // REP(i,m-1) if (cnt[i][n - 2]) cout << cnt[i+1][n-2] / cnt[i][n-2] << " ";
    // cout << endl;
    VL b(m);
    FORR(i,m-1,0){
        if (cnt[i + 1][n - 2] == 0) continue;
        b[i] = k / cnt[i + 1][n - 2];
        k -= b[i] * cnt[i + 1][n - 2];
    }
    // REP(i,m) cout << b[i] << " ";
    // cout << endl;
    string ans, s = "FESTIVAL";
    REP(i,m){
        ans += s[a[i]];
        ans += string(b[i], 'L');
    }
    cout << ans << endl;
    return 0;
}
