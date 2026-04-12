#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<ll> vec;
typedef vector<vec> mat;
ll dp[200001]={0};
int main(){
    ll n,A[200001],B[200002];
    cin>>n;
    rep(i,n) cin>>A[i];
    rep(i,n){
        if(i==1) B[2]=A[0];
        if(i%2&&i>1) B[i+1]=B[i-1]+A[i-1];
    }
    rep(i,n+1){
        if(i<2) continue;
        if(i%2==0) dp[i]=max(B[i],dp[i-2]+A[i-1]);
        else dp[i]=max(dp[i-2]+A[i-1],dp[i-1]);
    }
    //rep(i,n+1) cout<<dp[i]<<"\n";
    cout<<dp[n]<<"\n";
}