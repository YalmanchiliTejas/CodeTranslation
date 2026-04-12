#pragma GCC optimize "trapv"
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
#define ll long long
#define pb push_back
#define fo(i,a,b) for(int i=a;i<b;i++)
#define foe(i,a,b) for (int i=a;i<=b;i++)
ll dp[3000][3000];
ll fundp(int i,int j, ll *a){
    //cout<<i<<" "<<j<<endl;
    if (dp[i][j]!=1000000000000001) return dp[i][j];
    if (i==j)
    dp[i][j]=a[i];
    else
    {
        dp[i][j]=max(a[i]-fundp(i+1,j,a),a[j]-fundp(i,j-1,a));
    }
    return dp[i][j];
    
}
void solve()
{
    int n;
    cin>>n;
    ll a[n];
    fo(i,0,n) cin>>a[i];
    fo(i,0,n){
        fo(j,0,n) dp[i][j]=1000000000000001;
    }
    cout<<fundp(0,n-1,a)<<endl;

}
signed main()
{
   faster;
    //int t;cin>>t;
   // while(t--)
        solve();
}