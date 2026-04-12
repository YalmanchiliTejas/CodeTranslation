#include<bits/stdc++.h>
using namespace std;
 
typedef    long long          ll;
typedef    vector<long long>    vi; 
typedef    vector<vi>         vvi; 
typedef    pair<long,long>      ii; 
#define    sz(a)              long((a).size()) 
#define    pb                 push_back 
#define    mp                   make_pair
#define    all(c)             (c).begin(),(c).end() 
#define    tr(c,i)            for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define    present(c,x)       ((c).find(x) != (c).end()) 
#define    cpresent(c,x)      (find(all(c),x) != (c).end())  
#define    input(v,n)           for(ll i = 0 ; i<n ; i++) cin>>v[i]
#define    output(v,n)          for(ll i = 0 ; i<n ; i++) cout<<v[i]<<" "


ll dp[3002][3002];
ll a[3002];

ll fnd(ll i, ll j)
{
  if(dp[i][j])return dp[i][j];

  if(i == j)return a[i];
  dp[i][j] =  max(a[i]-fnd(i+1,j),a[j]-fnd(i,j-1));
  return dp[i][j];
}
 
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n,i;
  cin>>n;
  for(i=0;i<n;i++)
  {
    cin>>a[i];
  }
  cout<<fnd(0,n-1)<<"\n";

  return 0;
}
