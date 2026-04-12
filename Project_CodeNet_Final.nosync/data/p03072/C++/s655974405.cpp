#include <bits/stdc++.h>
const int MOD=1000000007;
const int INF=1000000000;
using namespace std;
typedef long long ll;
typedef tuple<ll,int,int> tup;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pair<int,int> > vp;
int n,h[25];
int main(int argc,char const* argv[])
{
  int ans=1;
  cin >> n;
  for(int i=0;i<n;i++)
    {
      cin >> h[i];
    }
  if(n==1)
    {
      cout << 1 << endl;
      return 0;
    }
  for(int i=1;i<n;i++)
    {
      bool cansee=true;
      for(int j=0;j<i;j++)
	{
	  if(h[j]>h[i])
	    {
	      cansee=false;
	    }
	}
      if(cansee) ans++;
    }
  cout << ans << endl;
  return 0;
}
