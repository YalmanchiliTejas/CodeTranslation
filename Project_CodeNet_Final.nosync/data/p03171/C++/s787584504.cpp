/* ****AWARE**** */
#include<bits/stdc++.h>
#include <limits.h> 
#define cut ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define ll          long long
#define pb          push_back
#define endl        '\n'
#define pii         pair< ll, ll>
#define vi          vector< ll>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll)x.size()
#define hell        1000000007
#define rep(i,a,b)  for(  ll i=a;i<b;i++)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp13       make_pair
using namespace std; 
#define MAX  3000
#define MODULO 2
using namespace std;   
#define hell 1000000007 
#define hell1 30000000000000000
#define time        cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
#define mysizeof(i) (char*)(&i+1)-(char *)(&i);
ll T;
//double dp[MAX][MAX];
vector<ll>v;
void solve()
{    ll i,j,n,a;
     cin>>n;
     for(i=0;i<n;i++)
     {
     	cin>>a;
     	v.pb(a);
     }
     ll dp[n][n];
      for(i=n;i>=0;i--)
      {
      	for(j=i;j<n;j++)
      	{
      		if(i==j)
      		{
      			dp[i][j]=v[i];
      			continue;
      		}
      		dp[i][j]=max(v[i]-dp[i+1][j],v[j]-dp[i][j-1]);
      	}
      }
   cout<<dp[0][n-1]<<"\n";
}
           
int main(){ 
cut; 
ll t; 
//cin>>t;
//T=t;
 t=1;
while(t--)
solve();
return 0;
}
     
