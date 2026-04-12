#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <set>
#include <map>
#define REP(i,n) for(ll i = 0; i < (ll)n; i++)
#define INF 1000000000000000
using namespace std;
typedef long long ll;
typedef double db;
typedef string str;

#define MAXN 3000
ll dp[MAXN][MAXN];

ll dfs(ll i, ll j){
  if(dp[i][j]!=-1) return dp[i][j];
  return dp[i][j] = max(dfs(i,i)-dfs(i+1,j),dfs(j,j)-dfs(i,j-1));
}

int main(){
  ll n;
  cin >> n;
  fill(dp[0],dp[n],-1);
  REP(i,n){
    cin >> dp[i][i];
  }
  cout << dfs(0,n-1) << endl;
  return 0;
}
