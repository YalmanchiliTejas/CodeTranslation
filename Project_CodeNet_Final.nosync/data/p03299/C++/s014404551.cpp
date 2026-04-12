#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <bitset>

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
#define REP(i, a, b) for(int i = int(a); i <= int(b); i++)
#define LOOP(i, v) for(int i = 0; i < v.size(); i++)
#define EPS 1e-9
#define INF 1e12
#define debug(x) cerr << "DEBUG : " << (#x) << " => " << (x) << endl

long long int MOD = 1000000007;

long long int pow2(long long int k)
{
  if(k == 0) return 1;
  long long int x = pow2(k/2);
  if(k & 1) return (((x*x)%MOD)*2)%MOD;
  else return (x*x)%MOD;
}

int main()
{
  int N;
  long long int h[100];
  long long int val[100];
  set<long long int> ss;
  set<long long int>::iterator it;
  map<long long int, int> mm;
  
  scanf("%d", &N);
  REP(i, 0, N-1)
  {
    scanf("%lld", &h[i]);
    ss.insert(h[i]);
  }
  
  int M = 0;
  for(it = ss.begin(); it != ss.end(); it++)
  {
    mm[*it] = M;
    val[M] = *it;
    M++;
  }
  // M = number of different heights
  
  long long int dp[100][101];
  
  long long int prevh = 1;
  REP(i, 0, M)
  {
    if(i == M) dp[0][i] = 2;
    else if(val[i] <= h[0]) dp[0][i] = ((pow2(val[i]-prevh+1)-2) * pow2(h[0]-val[i]))%MOD;
    else dp[0][i] = 0;
    prevh = val[i];
  }
  
  REP(j, 1, N-1)
  {
    REP(i, 0, M) dp[j][i] = 0;
    if(h[j] <= h[j-1])
    {
      REP(i, 0, M)
      {
        if(i < M && val[i] <= h[j]) dp[j][i] = (dp[j][i] + dp[j-1][i])%MOD;
        else dp[j][M] = (dp[j][M] + 2*dp[j-1][i])%MOD;
      }
    }
    else
    {
      long long int tot = 0;
      REP(i, 0, M)
      {
        if(i < M && val[i] <= h[j-1]) dp[j][i] = (dp[j][i] + dp[j-1][i]*pow2(h[j]-h[j-1]))%MOD;
        else tot = (tot+dp[j-1][i])%MOD;
      }
      REP(i, 0, M)
      {
        if(i < M && val[i] > h[j-1] && val[i] <= h[j]) dp[j][i] = (dp[j][i] + ((tot*(pow2(val[i]-val[i-1]+1)-2))%MOD) * pow2(h[j]-val[i]))%MOD;
        else if(i == M) dp[j][i] = (dp[j][i] + tot*2)%MOD;
      }
    }
  }
  
  long long int ans = 0;
  
  REP(i, 0, M) ans = (ans + dp[N-1][i])%MOD;
  
  cout << ans << endl;
  
    
  return 0;
}