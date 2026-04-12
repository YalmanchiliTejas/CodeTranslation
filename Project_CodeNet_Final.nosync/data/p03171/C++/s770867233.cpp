#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define pii pair<ll,ll>
#define debug(a) cout<<a<<'\n'
#define maxn 3009 /// Still trying to be normal
#define MOD 1000000007
#define F first
#define S second
#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define per(i, b, a) for(ll i = b-1; i>=a ; i--)
#define trav(a, x) for(auto& a : x)
#define allin(a , x) for(auto a : x)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
using namespace std;
const ll INF = 1e14 + 15;
ll dp[maxn][maxn][3];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>n;
    ll vet[n+2];
    rep(i,0,n){
        cin>>vet[i];
    }
    per(i,n+1,0){
        rep(j,0,n+1){
            if(i>j){
                continue;
            }
            else{
                dp[i][j][1]=max(dp[i+1][j][2]+vet[i],dp[i][j-1][2]+vet[j]);
                dp[i][j][2]=min(dp[i+1][j][1]-vet[i],dp[i][j-1][1]-vet[j]);
            }
        }
    }
    cout<<dp[0][n-1][1]<<'\n';
    return 0;   
}