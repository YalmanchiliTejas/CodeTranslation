#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <assert.h>

using namespace std;

#define N 100005
int dp[N][2];
vector<int> adj[N];

int dfs(int node,int p) {
  int ret = 0;
  int sz = adj[node].size(),ch;
  int sum = 0;// matched
  //one unmatch  + match
  int maxi = -2;
  for(int i=0;i<sz;++i) {
    ch = adj[node][i];
    if(ch!=p) {
      dfs(ch,node);
      sum += dp[ch][1];
      maxi = max(maxi,-dp[ch][1] +dp[ch][0]);
    }
  }
  dp[node][0] = sum;
  dp[node][1] = sum + maxi + 1;
  return max(dp[node][0],dp[node][1]);
}
void solve() {
  int n;
  scanf("%d",&n);

  if(n%2==1) {
    printf("First\n");
    return;
  }
  for(int i=0;i<n-1;++i) {
    int a,b;scanf("%d %d",&a,&b);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  int R = dfs(1,0);
  if(R*2 == n) {
    printf("Second\n");
  } else {
    printf("First\n");
  }
}

int main() {
  //freopen("input.txt","r",stdin);
  solve();
  return 0;
}
