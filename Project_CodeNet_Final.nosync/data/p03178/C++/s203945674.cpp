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
#include <iomanip>
using namespace std;

#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<long double> VD;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VD> VVD;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

template<typename T> void chmin(T &a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T &a, T b) { if (a < b) a = b; }

int in() { int x; scanf("%d", &x); return x; }
ll lin() { ll x; scanf("%lld", &x); return x; }
#define INF 1LL<<60

int main() {
    int D;
    ll mod = 1e9+7;
    string K;
    cin >> K >> D;
    
    // dp[i][j][k]: 先頭からi桁までの数の総和をDで割った余りがkであるもの　かつ　条件が j=1 => tight
    vector<vector<vector<ll>>> dp(K.length(), vector<vector<ll>>(2, vector<ll>(D)));
    for(int k=0; k<int(K[0]-'0'); k++) dp[0][0][k%D] += 1;
    dp[0][1][int(K[0]-'0')%D] = 1;

    for(int i=1; i<K.length(); i++) {
        for(int k=0; k<D; k++) {
            for(int s=0; s<=9; s++) {
                if(s == int(K[i] - '0')) {
                    (dp[i][1][(k+s)%D] += dp[i-1][1][k]) %= mod;
                }
                else if(s<int(K[i]-'0')) {
                    (dp[i][0][(k+s)%D] += dp[i-1][1][k]) %= mod;
                }
                (dp[i][0][(k+s)%D] += dp[i-1][0][k]) %= mod;
            }
        }
    }

    // cerr << "debug" << endl;
    // for(int i=0; i<K.length(); i++) {
    //     for(int j=0; j<D; j++) cerr << dp[i][0][j] << " "; cerr << endl;
    // }
    ll ans = (dp[K.length()-1][0][0] + dp[K.length()-1][1][0] - 1 + mod) % mod;
    cout << ans << endl;
    return 0;
}