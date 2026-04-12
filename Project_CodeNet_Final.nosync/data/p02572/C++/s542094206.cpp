#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1001001001LL;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){ 
    int n; cin >> n;
    vector<ll> A(n), S(n+1); 
    rep(i, n){cin >> A[i]; S[i+1] = S[i] + A[i];}

    ll res = 0;
    rep(i, n){
        ll num = (S[n]- S[i+1]) % MOD;
        ll add = (A[i] * num) % MOD;
        res = (res + add) % MOD;
    }
    cout << res << ln;
}

