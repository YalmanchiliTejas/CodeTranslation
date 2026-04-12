#include<bits/stdc++.h>
#define MIN -1000000
using namespace std;
typedef long long ll;
typedef pair <int,int> pii;
typedef pair<ll,ll> pll;
bool visited[100005];
const int max_N=1e5+10;
ll N,X;
ll layer[55];
ll paty[55];
ll ans=0;
ll dfs(ll level,ll eat)
{
  if(eat<=1) return 0;
  else if(eat<layer[level-1]+1)
    {
      return dfs(level-1,eat-1);
    }
  else if(eat==layer[level-1]+1)
    {
      return paty[level-1];
    }
  else if(eat==layer[level-1]+2)
    {
      return 1+paty[level-1];
    }
  else if(eat<layer[level-1]*2+2)
    {
      return 1+paty[level-1]+dfs(level-1,eat-layer[level-1]-2);
    }
  else if(eat>=layer[level-1]*2+2)
    {
      return 1+2*paty[level-1];
    } 
}

int main(void)
{
  cin >> N >> X;
  layer[0]=1;
  paty[0]=1;
  for (int i = 1; i <= N; ++i)
    {
      layer[i]=layer[i-1]*2+3;
      paty[i]=paty[i-1]*2+1;
    }
  cout << dfs(N,X) << endl;;
  
  return 0;
}
