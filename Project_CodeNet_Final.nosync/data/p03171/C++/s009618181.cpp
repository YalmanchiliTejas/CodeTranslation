#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define test() ull t;cin>>t;while(t--)
#define pb push_back
#define mkp make_pair
#define nl cout<<endl
#define MOD 1000000007
#define loop(i,start,end) for(ull i=start;i<end;i++)
#define N 3001
#define all(v) v.begin(),v.end()
#define oa(a,n) for(int i=0;i<n;i++)cout<<a[i]<<" ";nl
#define ov(a) for(int i=0;i<a.size();i++)cout<<a[i]<<" ";nl
vector<ll>v;
ll dp[N][N];
int main() 
{
  ll n,sm;cin>>n;
  v.resize(n);
  loop(i,0,n)cin>>v[i],sm+=v[i];

  for(int i = n;i>=0;i--)
  {
  	for(int j = i;j<n;j++)	
  	{
  		if(i==j)dp[i][j] = v[i];
  		else dp[i][j] = max(v[i] - dp[i+1][j],v[j]-dp[i][j-1]);
  	}
  }
  cout<<dp[0][n-1]<<endl;

  return 0;
}