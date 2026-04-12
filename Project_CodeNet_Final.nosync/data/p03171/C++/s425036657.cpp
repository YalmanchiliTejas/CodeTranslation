#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define NUM 1000000009
#define MAX 100001
#define INF LLONG_MAX
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,tmp;
    cin>>n;
    vector<ll> v;
    ll sum = 0;
    for(int i=0;i<n;i++){
        cin>>tmp;
        sum+=tmp;
        v.pb(tmp);
    }
    vector<vector<ll>> dp(n+1,vector<ll>(n+1,0));
    for(int k=0;k<n;k++){
        for(int i=0,j=k;j<n;i++,j++){
            ll a = (i<n && j>0)?dp[i+1][j-1]:0;
            ll b = (i<n-1)?dp[i+2][j]:0;
            ll c = (j>1)?dp[i][j-2]:0;
            dp[i][j]=max(v[i]+min(a,b),v[j]+min(a,c));
        }
    }
    cout<<dp[0][n-1]-(sum-dp[0][n-1])<<endl;
    return 0;
}
