/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lpair = pair<ll, ll>;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i=(m);i<(n);i++)
#define rrep(i,m,n) for(ll i=(m);i>=(n);i--)
#define printa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};
void print() {}
template <class H,class... T>
void print(H&& h, T&&... t){cout<<h<<" \n"[sizeof...(t)==0];print(forward<T>(t)...);}
ll dp[3010][3010] = {};
ll a[3010];
ll N;
ll calc(ll lv, ll rv){
    ll &res = dp[lv][rv];
    if(~res) return res;
    res = 0;
    ll cnt = N - (rv - lv);
    if(cnt % 2 == 0){
        res = max(a[lv] + calc(lv+1, rv), a[rv-1] + calc(lv, rv-1));
        return res;
    }else{
        res = min(-a[lv] + calc(lv+1, rv), -a[rv-1] + calc(lv, rv-1));
        return res;
    }


    return res;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    rep(i,0,N) cin >> a[i];
    rep(i,0,N+1){
        rep(j,0,N+1){
            dp[i][j] = -1;
        }
    }
    rep(i,0,N+1) dp[i][i] = 0;
    ll ans = calc(0, N);
    print(ans);
    

}