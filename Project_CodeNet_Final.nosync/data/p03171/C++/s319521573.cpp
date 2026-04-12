#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
#define ff first
#define ss second
#define se set<ll>
#define vec vector<ll>
#define inf 10000000000000000
#define pri 100000000007
bool mark[100005];
vec adj[100005];
ll counter;
vec cnt;
vector<string> forsubs;
ll a=0;
ll b[3000];
ll n;
ll f=0;
ll dp[3000][3000]={0};

ll ans(ll i,ll j)
  {
    if(dp[i][j]!=pri)return dp[i][j];
    if(i>j)
      return 0;
    else
    {
      if(a)
      { 
        if((j-i+1)%2==0)
           f=max(ans(i+1,j)+b[i],ans(i,j-1)+b[j]);
         else
          f=min(ans(i+1,j)-b[i],ans(i,j-1)-b[j]);
      }

      else
      {
        if((j-i+1)%2!=0)
           f=max(ans(i+1,j)+b[i],ans(i,j-1)+b[j]);
         else
          f=min(ans(i+1,j)-b[i],ans(i,j-1)-b[j]);
      }
return dp[i][j]=f;
  }
  }
         
   



int main()
{    
 

   #ifdef APNA_IO
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
   #endif
          ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    for(ll i=0;i<3000;i++){
      for(ll j=0;j<3000;j++){
        dp[i][j]=pri;
      }
    }
    cin>>n;
    
    

    if(n%2==0)
      a=1;

    for(ll i=0;i<n;i++)
    {
      cin>>b[i];
    }

    ans(0,n-1);

    cout<<f<<endl;



}