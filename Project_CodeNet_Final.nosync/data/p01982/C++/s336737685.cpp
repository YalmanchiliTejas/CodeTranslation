#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <tuple>
#include <queue>
#include <set>
#include <cstdio>
#include <climits>
#include <cmath>
#include <array>
#include <functional>
#include <list>
#include <iomanip>
#include <set>
const int MOD=1000000007;
const int INF=1000000000;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
const double eps=1e-9;
const int inf=1e9;
typedef pair<int,int> P;
int n,l,r;
int main(void)
{
  while(cin >> n >> l >> r && n)
    {
      vi A;
      for(int i=0;i<n;i++)
	{
	  int a;
	  cin >> a;
	  A.push_back(a);
	}
      int ans=0;
      for(int j=l;j<=r;j++)
	{
	  bool ca=false;
	  for(int i=0;i<n;i++)
	    {
	      if(j%A[i]==0)
		{
		  ca=true;
		  if((i+1)%2!=0) 
		    {
		      ans++;
		    }
		  break;
		}
	    }
	  if(ca) continue;
	  else
	    {
	      if(n%2==0) ans++;
	    }	    
	}
      cout << ans << endl;
    }
  return 0;
}

