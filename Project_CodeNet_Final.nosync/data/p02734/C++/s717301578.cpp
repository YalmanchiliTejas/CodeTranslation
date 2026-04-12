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

const ll mod = 998244353;

int main(void){
    int n, s;
    cin >> n >> s;
    VI a(n);
    REP(i,n) a[i] = in();
    ll ans = 0;
    VL dp(s + 1);
    dp[0] = 1;
    REP(i,n){
        if (a[i] <= s) ans = (ans + (n - i) * dp[s - a[i]]) % mod;
        FORR(j,s,a[i]){
            dp[j] = (dp[j] + dp[j - a[i]]) % mod;
        }
        dp[0]++;
    }
    cout << ans << endl;
    return 0;
}
