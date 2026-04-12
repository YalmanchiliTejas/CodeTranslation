//submitted by Himj
#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define pb push_back
#define fi first
#define se second
#define fr(i,s,e) for(i=s;i<e;i++)
#define ms(arr,val) memset(arr,val,sizeof(arr))
using namespace std;

const int mxn=3e3+1;
ll arr[mxn],dp[mxn][mxn];
ll solve(int i,int j)
{
  if(i>j)
    return 0;
  if(dp[i][j]!=1e18)
    return dp[i][j];
  return dp[i][j]=max(arr[i]-solve(i+1,j),arr[j]-solve(i,j-1));
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

  int t=1;
  //cin>>t;
    while(t--){
      int i,j;
      int n;
      cin>>n;
      fr(i,0,n)
      cin>>arr[i];
      fr(i,0,n)
      {
        fr(j,0,n)
        dp[i][j]=1e18;
      }
      ll ans=solve(0,n-1);
      cout<<ans;
      
       
    }
  return 0;
  }

