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

const int mxn=2e5+1;
string s;
ll dp[20001][2][101],d,n;
ll solve(int i,int tight,int md)
{
  if(i==n)
    return md==0;
  if(dp[i][tight][md]!=-1)
    return dp[i][tight][md];
  int e=9;
  if(tight)
    e=s[i]-'0';
  int j;
  ll ans=0;
  fr(j,0,e+1)
  {
    int atight=0;
    if(j==e and tight)
      atight=1;
    ans=(ans+solve(i+1,atight,(md+j)%d))%mod;
  }
  return dp[i][tight][md]=ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

  int t=1;
  //cin>>t;
    while(t--){
      cin>>s>>d;
      n=s.size();
      ms(dp,-1);
      ll ans=solve(0,1,0);
      ans=(ans-1+mod)%mod;
      cout<<ans;
      
       
    }
  return 0;
  }

