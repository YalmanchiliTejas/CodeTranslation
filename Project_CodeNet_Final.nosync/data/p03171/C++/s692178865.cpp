//om nama sivaya
#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define pb push_back
using namespace std;
ll a[3001],x=0,y=0,su=0;
ll dp[3005][3005];
ll ans(int i,int j){
    if(i==j)return dp[i][j]=a[i];
    else if(i>j)return dp[i][j]=-1;
    if(i+1==j)
    return dp[i][j]=max(a[i],a[j]);
    if(dp[i][j])
    return dp[i][j];
    else
    return dp[i][j] = max(a[i]+min(ans(i+2,j),ans(i+1,j-1)),a[j]+min(ans(i+1,j-1),ans(i,j-2)));
}
void solve(){
    int n;
    cin>>n;
    //int a[n];
    for(int i=0;i<n;i++){cin>>a[i];su+=a[i];}
    x=ans(0,n-1);
    y=su-x;
    cout<<(x-y);
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tt=1;
    //cin>>tt;
    while(tt--){
        solve();
    }
}
