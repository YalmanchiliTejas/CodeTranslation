#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<ll> vec;
typedef vector<vec> mat;
ll n,s,A[200001],ans=0,mod=998244353;
ll dp[3001][3001]={0};
int main(){
    cin>>n>>s;
    rep(i,n) cin>>A[i];
    rep(i,n) if(A[i]<=s) dp[i+1][A[i]]=i+1+(i+1)*(n-i-1)*(A[i]==s);
    rep(i,n)rep(j,s+1){
        if(j<s){
            (dp[i+1][j]+=dp[i][j])%=mod;
            if (j>=A[i]) (dp[i+1][j]+=dp[i][j-A[i]])%=mod;
        }
        else{
            (dp[i+1][j]+=dp[i][j])%=mod;
            if (j>=A[i]) (dp[i+1][j]+=(n-i)*dp[i][j-A[i]])%=mod;
        }
    }
    cout<<dp[n][s];
}