//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define mod 1000000007
#define fi first
#define se second
#define pii pair<long long,long long>
#define int long long
#define endl '\n'
#define pll pair<long long,long long>
#define LONGLONG_MAX 100000000000000
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
long long power(long long a,long long b){
    long long ans=1;
    while(b>0){
        if(b&1){ans=(ans*a);}
                a=(a*a);
                b>>=1;
        }
    return ans;
        
}
int dp[200005][5];
int fun(int i,int j,int a[],int n){
    if(j>=3)return LLONG_MIN;
    if(i>=n){
        return 0;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    int ans=LLONG_MIN;
    ans=max(ans,fun(i+2,j,a,n));
    ans=max(ans,fun(i+3,j+1,a,n));
    ans=max(ans,fun(i+4,j+2,a,n));
    return dp[i][j]=ans+a[i];
}
int fun1(int i,int j,int a[],int n){
    if(j>=2)return LLONG_MIN;
    if(i>=n){
        return 0;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    int ans=LLONG_MIN;
    ans=max(ans,fun1(i+2,j,a,n));
    ans=max(ans,fun1(i+3,j+1,a,n));
    ans=max(ans,fun1(i+4,j+2,a,n));
    return dp[i][j]=ans+a[i];
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    srand(time(0));
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n%2==0){
        memset(dp,-1,sizeof(dp));
        int ans=max(fun1(0,0,a,n),max(fun1(1,1,a,n),fun1(2,2,a,n)));
        cout<<ans;
        return 0;
    }
    memset(dp,-1,sizeof(dp));
    int ans=max(fun(0,0,a,n),max(fun(1,1,a,n),fun(2,2,a,n)));
    cout<<ans;
    return 0;
}
