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

int n,m,k;
int dark[105];
int road[105][105];
int dp[1<<16];
int d[16];
int main(int argc,char const* argv[])
{
  cin >> n >> m >> k;
  memset(dark,-1,sizeof(dark));
  memset(dp,-1,sizeof(dp));
  for(int i=0;i<m;i++)
    {
      cin >> d[i];
      d[i]--;
      dark[d[i]]=i;
    }
  for(int i=0;i<n;i++)
    {
      for(int j=0;j<k;j++)
	{
	  cin >> road[i][j];
	  road[i][j]--;
	}
    }
  dp[(1<<m)-1]=0;
  queue<int> que;
  que.push((1<<m) -1);
  while(!que.empty())
    {
      int now=que.front();
      que.pop();
      for(int j=0;j<k;j++)
	{
	  int next=0;
	  for(int l=0;l<m;l++)
	    {
	      if((now & (1<<l))==0) continue;
	      int nextroom=road[d[l]][j];
	      if(dark[nextroom]>=0) next|=(1<<dark[nextroom]);
	    }
	  if(dp[next]==-1)
	    {
	      dp[next]=dp[now]+1;
	      que.push(next);
	    }
	}
    }
  cout << dp[0] << endl;
  return 0;
}

