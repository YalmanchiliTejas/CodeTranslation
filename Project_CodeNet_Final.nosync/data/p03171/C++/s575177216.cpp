//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define mod 998244353
#define fi first
#define se second
#define pii pair<int,int>
#define int long long
#define endl '\n'
#define pll pair<long long,long long>
#define LONGLONG_MAX 100000000000000
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
long long power(long long a,long long b){
    long long ans=1;
    while(b>0){
        if(b&1){ans=(ans*a)%mod;}
                a=(a*a)%mod;
                b>>=1;
        }
    return ans;
        
}
int dp[3005][3005];
int fun(int i,int j,int k,int a[],int n){
    if(i>j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(k==1){
        int ans=LLONG_MAX;
        ans=min(ans,fun(i+1,j,(k+1)%2,a,n)-a[i]);
        ans=min(ans,fun(i,j-1,(k+1)%2,a,n)-a[j]);
        return dp[i][j]=ans;
    }
    else{
        int ans=LLONG_MIN;
        ans=max(ans,fun(i+1,j,(k+1)%2,a,n)+a[i]);
        ans=max(ans,fun(i,j-1,(k+1)%2,a,n)+a[j]);
        return dp[i][j]=ans;
    }
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<fun(0,n-1,0,a,n);
    return 0;
}