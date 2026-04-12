#include <iostream>
#include <vector>
#include <string>
#include <algorithm>  // sort, 二分探索, etc
#include <iomanip>  // setprecision (浮動小数点の出力の誤差)
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <cmath>

#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=a,i##_len=(b);i<i##_len;++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()
#define cauto const auto&
#define UNIQUE(v) (v).erase( unique(all(v), (v).end() );
#define SZ(x) ((ll)(x).size()) // sizeをsize_tからllに直しておく
#define MAX(x) *max_element(all(x))
#define MIN(x) *min_element(all(x))
#define INF 1000000000000
#define MOD 1000000007
#define perm(c) sort(all(c));for(bool c##p=1;c##p;c##p=next_permutation(all(c)))

using namespace std;
using ll = long long;
using ull = unsigned long long;

template<class T>bool chmax(T &a, const T &b){if(a<b){a=b;return true;}return false;}
template<class T>bool chmin(T &a, const T &b){if(a>b){a=b;return true;}return false;}

const char newl = '\n';

ll qp(ll a,ull b){ll ans=1;do{if(b&1u)ans*=a;a*=a;}while(b>>=1u);return ans;}
ll qp(ll a,ull b,ll mod){ll ans=1;do{if(b&1u)ans=ans*a%mod;a=a*a%mod;}while(b>>=1u);return ans;}
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll comb(int n, int r) {
    vector<vector<ll> > v(n+1, vector<ll>(r+1, 0));
    for(int i=0;i<n+1;i++) {v[i][0]=1; if(i < r+1)v[i][i]=1; }
    for(int i=1;i<n+1;i++) {for(int j=1;j<min(i,r+1);j++) {v[i][j]=v[i-1][j-1]+v[i-1][j];}}
    return v[n][r];
}

// INT_MAX   = 2.1e+09 (2147483647)
// LONG_MAX  = 9.2e+18 (9223372036854775807)
// LLONG_MAX = 9.2e+18 (9223372036854775807)


int main() {
    ll n;
    cin >> n;

    if (n >= 30) {
        cout << "Yes" << newl;
    } else {
        cout << "No" << newl;
    }

    return 0;
}
