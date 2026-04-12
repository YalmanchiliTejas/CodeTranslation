#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(c) (c).begin(), (c).end()
#define pb push_back
#define eb emplace_back
const long long INF = 1LL<<60; // 仮想的な無限大の値;
using namespace std;
using ll = long long;
using P  = pair<int, int>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll MOD = 1000000007;
int main()
{
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    ll ans = 0;
    // rep(i, N-1)rep2(j, i+1, N)
    // {
    //     ll a = A[i]%MOD;
    //     ll b = A[j]%MOD;
    //     ll c = (a*b)%MOD;
    //     ans += c;
    //     ans %= MOD;
    // }
    // ll sub = 0;
    // rep2(i, 1, N)
    // {
    //     sub += A[i];
    // }
    // sub %= MOD;
    // rep(i, N-1)
    // {
        
    //     ans += ((A[i]*sub)%MOD);
    //     sub -= A[i+1];
    //     sub %= MOD;
    // }
    // cout << ans << endl;
    vector<ll> S(N);
    S[0] = 0;
    S[1] = A[0];
    rep2(i, 2, N)
    {
        S[i] = (S[i-1] + A[i-1])%MOD;
        //cout << S[i] << endl;
    }
    rep2(i, 0, N-1)
    {
        ll x = A[i+1]*S[i+1];
        ans += (x%MOD);
    }
    ans %= MOD;
cout << ans << endl;
     return 0;
}