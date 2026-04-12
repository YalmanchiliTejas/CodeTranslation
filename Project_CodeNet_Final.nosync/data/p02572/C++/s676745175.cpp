#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define frn(i,a,b) for(int i=a;i>=b;i--)
#define vi vector<int>
#define pii pair<int,int>
#define vpi vector<pair<int,int>>
#define vvi vector<vector<int>>
#define test int t;cin>>t; while(t--)
#define mp make_pair
#define pb push_back
#define pu push
#define fi first
#define se second
#define mod 1000000007
typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> seti;
void fast() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int32_t main(){
    //fast();
    int n;
    cin>>n;
    int a[n+1];
    fr(i,0,n) cin>>a[i];
    int dp[n+1];
    memset(dp,0,sizeof dp);
    dp[0] = a[0];
    fr(i,1,n){
      dp[i] = dp[i-1]+a[i];
      dp[i] = dp[i]%mod;
    }
    int p = 0;
    fr(i,0,n-1){
      p += (a[i]*(((dp[n-1]-dp[i])%mod+mod)%mod))%mod;
      p = p%mod;
    }
    cout<<p;
    return 0;
}