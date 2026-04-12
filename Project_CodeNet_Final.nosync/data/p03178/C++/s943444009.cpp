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
ll dp[10010][110][2] = {};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string K;
    ll D;
    cin >> K >> D;
    ll keta = K.size();
    dp[0][0][0] = 1;
    rep(i,0,keta){
        rep(j,0,D){
            ll d = K[i] - '0';
            rep(k,0,d+1){
                if(k == d){
                    dp[i+1][(j+k)%D][0] += dp[i][j][0];
                    dp[i+1][(j+k)%D][0] %= MOD;
                }else{
                    dp[i+1][(j+k)%D][1] += dp[i][j][0];
                    dp[i+1][(j+k)%D][1] %= MOD;
                }
            }
            rep(k,0,10){
                dp[i+1][(j+k)%D][1] += dp[i][j][1];
                dp[i+1][(j+k)%D][1] %= MOD;
            }
        }
    }
    ll ans = (dp[keta][0][0] + dp[keta][0][1]) % MOD;
    print((ans-1+MOD)%MOD);


    

}