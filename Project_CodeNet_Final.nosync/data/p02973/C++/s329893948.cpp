#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
int main(){
    int n,INF=1e9+1;
    cin>>n;
    vector<int> A(n),dp(n+1,INF);
    rep(i,n) cin>>A[i];
    reverse(A.begin(),A.end());
    dp[0]=-1;
    rep(i,n) dp[upper_bound(dp.begin(),dp.end(),A[i])-dp.begin()]=A[i];
    cout<<lower_bound(dp.begin(),dp.end(),INF)-dp.begin()-1;
}