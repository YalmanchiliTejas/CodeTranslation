#include<bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define mod 1000000007
#define test ll t; cin>>t; while(t--)
typedef long long int ll;
ll n;
ll dp[3001][3001];
bool vis[3001][3001];
ll a[3001];
ll solve(int l,int r){
    if(vis[l][r]){
        return dp[l][r];
    }
    vis[l][r]=true;
    if(l==r){
        return dp[l][r]=a[l];
    }
    dp[l][r]=max(a[l]-solve(l+1,r),a[r]-solve(l,r-1));
    return dp[l][r];
}
int main() {
    FIO;
    //test
    {
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        memset(vis,false,sizeof(vis));
        cout<<solve(1,n)<<endl;
    }
	return 0;
}
