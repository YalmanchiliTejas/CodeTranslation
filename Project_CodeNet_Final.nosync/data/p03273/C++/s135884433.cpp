#include<bits/stdc++.h>
#include<time.h>
#include<stdlib.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse4")
#define pb push_back
#define mp make_pair
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define pll pair<ll,ll>
#define vll vector<ll,ll>
#define all(a) (a).begin(),(a).end()
#define ff first
#define ss second
#define sz(x) (ll)x.size()
#define hell 1000000007
#define repf(i,a,b) for(ll i=a;i<b;i++)
#define repb(i,a,b) for(ll i=a;i>b;i--)
#define lbnd lower_bound
#define ubnd upper_bound
#define bs binary_search
#define gcd(a,b) __gcd((a),(b))
#define EPS 1e-12
#define lcm(a,b) ((a)*(b))/__gcd((a),(b))
#define sqrt sqrtl
#define cbrt cbrtl
using namespace std;
char a[200][200];
ll row[200],col[200];
int main()
{
  IOS
  
  ll i,j;
  ll n,m;
  cin>>n>>m;
  for(i=1;i<=n;i++)
  {
    string s;
    cin>>s;
    for(j=1;j<=m;j++)
      a[i][j]=s[j-1];
  }
  for(i=1;i<=n;i++)
  {
    for(j=1;j<=m;j++)
      if(a[i][j]=='#')
        break;
    if(j>m)
      row[i]=1;
  }
  for(j=1;j<=m;j++)
  {
     for(i=1;i<=n;i++)
      if(a[i][j]=='#')
        break;
      if(i>n)
        col[j]=1;
  }
  for(i=1;i<=n;i++)
    if(!row[i])
    {
      for(j=1;j<=m;j++)
        if(!col[j])
          cout<<a[i][j];
      cout<<"\n";
    }
 
  return 0;
}
