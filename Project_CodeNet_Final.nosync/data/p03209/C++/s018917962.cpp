#include<bits/stdc++.h>
#define MIN -1000000
using namespace std;
typedef long long ll;
typedef pair <int,int> pii;
typedef pair<ll,ll> pll;
ll N,X;
vector<pair<ll,ll> > shops;
ll paty[55],bans[55],layer[55];

ll dfs(ll dim,ll eat)
{
  if(eat>=(layer[dim]-1))
    {
      return paty[dim];
    }
  else if(eat<=1)
    {
      return 0;
    }
  else if(eat<=layer[dim-1]+1)
    {
      return dfs(dim-1,eat-1);
    }
  else if(eat==2+layer[dim-1])
    {
      return paty[dim-1]+1;
    }
  else if(eat>layer[dim-1]+2 && eat<=2+2*layer[dim-1])
    {
      return paty[dim-1]+1+dfs(dim-1,eat-2-layer[dim-1]);
    }
}

int main(void)
{
  paty[0]=1,bans[0]=0;
  layer[0]=1;
  cin >> N >> X;
 ll dim=N;
 ll eat=X;
 for (int i=1; i <= N; ++i)
   {
     paty[i]=2*paty[i-1]+1;
     bans[i]=2*bans[i-1]+2;
     layer[i]=paty[i]+bans[i];
   }
 if(N==1)
   {
     if(X<=4) cout << X-1 << endl;
     else cout << 3 << endl;
     return 0;
   }
 cout << dfs(dim,eat) << endl;;
 return 0;
}
     
