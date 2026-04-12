#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i) 
#define PI acos(-1)
#define pcnt __builtin_popcountll
#define rng(a) a.begin(), a.end()
#define sz(x) (int)(x).size()
#define v(T) vector<T>
#define vv(T) v(v(T))
#define fi first
#define se second

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;

template<typename T>inline istream& operator>>(istream&i,v(T)&v)
{rep(j,sz(v))i>>v[j];return i;}
template<typename T1,typename T2>inline istream& operator>>(istream&i,pair<T1,T2>&v)
{return i>>v.fi>>v.se;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) {if (a > b) { a = b; return true; } return false; }

ll INF = 1001001001;
ll LINF = 1001001001001001001ll;

ll n;
vl as;
vvl dp;

ll dfso(ll m, ll d) {
    if (m == n / 2) return 0;
    if (dp[m][d] != -LINF) return dp[m][d];
    ll res = -LINF;
    chmax(res, as[m * 2 + d] + dfso(m + 1, d));
    if (d <= 1) chmax(res, as[m * 2 + d + 1] + dfso(m + 1, d + 1));
    if (d == 0) chmax(res, as[m * 2 + d + 2] + dfso(m + 1, d + 2));
    return dp[m][d] = res;
}

ll dfse(ll m, ll d) {
    if (m == n / 2) return 0;
    if (dp[m][d] != -LINF) return dp[m][d];
    ll res = -LINF;
    chmax(res, as[m * 2 + d] + dfse(m + 1, d));
    if (d == 0) chmax(res, as[m * 2 + d + 1] + dfse(m + 1, d + 1));
    return dp[m][d] = res;
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin>>n;
    as = vl(n);
    cin>>as;
    dp = vvl(n / 2, vl(3, -LINF));
    if (n % 2) {
        cout<<dfso(0, 0)<<endl;
    }
    else {
        cout<<dfse(0, 0)<<endl;
    }
}