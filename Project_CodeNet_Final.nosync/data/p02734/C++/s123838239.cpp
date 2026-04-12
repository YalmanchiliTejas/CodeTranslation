#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll,ll>;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep2(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
const ll INF = 1LL<<60;
const ll MOD = 998244353;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,s;cin>>n>>s;
    vector<ll> a(n);rep(i,n)cin>>a[i];
    vector<vector<ll>> dp1(n+1,vector<ll>(s+1,0));
    vector<vector<ll>> dp2(n+1,vector<ll>(s+1,0));
    //dp1[i][j]:N=i,S=jに対するl*(n-r+1)の和
    //dp2[i][j]:N=i,S=jに対するlの和
    
    for(int i=0; i<=n; i++){
        if(i==0)continue;
        ll A = a[i-1];
        for(int j=0; j<=s; j++){
            if(A>j){
                dp1[i][j]=dp1[i-1][j]+dp2[i-1][j];
                dp2[i][j]=dp2[i-1][j];
            }else if(A==j){
                dp1[i][j]=dp1[i-1][j]+dp2[i-1][j]+i;
                dp2[i][j]=dp2[i-1][j]+i;
            }else{
                dp1[i][j]=dp1[i-1][j]+dp2[i-1][j]+dp2[i-1][j-A];
                dp2[i][j]=dp2[i-1][j]+dp2[i-1][j-A];
            }
            dp1[i][j]%=MOD;
            dp2[i][j]%=MOD;
        }
    }

    cout<<dp1[n][s];
    return 0;
}