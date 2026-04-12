#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<ll> vec;
typedef vector<vec> mat;
ll dp[200001][2][100];
int main(){
    string s;
    ll d,x,mod=1e9+7;
    cin>>s>>d;
    dp[0][1][0]=1;
    rep(i,s.size())rep(j,2)rep(k,d){
        if(j==0) x=9;
        else x=s[i]-'0';
        rep(l,x+1) (dp[i+1][j&&l==x][(k+l)%d]+=dp[i][j][k])%=mod;
    }
    cout<<(dp[s.size()][0][0]+dp[s.size()][1][0]-1+mod)%mod<<"\n";
}