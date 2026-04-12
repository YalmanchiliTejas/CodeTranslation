#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int mex=5000001;
#define ll long long 
#define test int t;cin>>t;while(t--)
#define fast  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fo(i,a,n) for(int i=a;i<n;i++)
#define rfo(i,a,b) for(int i=a;i>=b;i--)
#define bg begin()
#define en end()
#define fi first
#define se second
#define ub upper_bound
#define lb lower_bound
#define pb push_back
#define veci vector<int>
#define veclli vector<long long int> 
#define all(x) x.begin(),x.end()
#define sci(x) scanf("%d",&x);
#define scc(x) scanf("%c",&x);
#define scs(x) scanf("%s",x);
#define debug(arr,n) for(int i=0;i<n;i++) printf("%d ",arr[i]);
#define sz(x) x.size()
#define loop(x) for(auto it=x.begin();it!= x.end();it++) 

int main()
{
    ll int dp[4][105],fact[101];
    fact[0]=1;
    fo(i,1,101)
    fact[i]=fact[i-1]*i;
    fo(i,0,4)
    fo(j,0,101)
    {
        if(j>=i)
        {
            if(i==1)
        dp[i][j]=j;
        else if(i==2)
        dp[i][j]=(j*(j-1))/2;
        else dp[i][j]=(j*(j-1)*(j-2))/6;
        }
        else dp[i][j]=0;
        fo(k,1,i+1)
        dp[i][j]*=9;
    }
    fo(j,0,101)
    dp[0][j]=1;
  string s;
  cin>>s;
  int k;
  cin>>k;
  int y=k;
  int n=sz(s);
  ll int ans=0,cnt=0;
  fo(i,0,n)
  {
      
      ll int h=(s[i]-'0'-1);
      if(h>=0) cnt++;
    //cout<<n-i-1<<" "<<k<<" "<<h<<endl;
      if(h>0)
      ans=ans+h*dp[k-1][n-i-1];
      if(h>=0)
      {
      ans+=dp[k][n-i-1];
      //cout<<dp[k][n-i-1]<<" "<<dp[k-1][n-i-1]<<endl;
      
      k--;
      }
      if(k==0) break;
  }
  int fg=0;
  if(cnt==y) fg=1;
 
  cout<<ans+fg;
  
}