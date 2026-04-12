#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include <complex>

#include <functional>
#include <cassert>

typedef long long ll;
using namespace std;

#define debug(x) cerr << #x << " = " << (x) << endl;


#define mod 1000000007 //1e9+7(prime number)
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define SIZE 100010

vector<int> G[SIZE];
int n,k;
int sum[SIZE], sumk[SIZE];
int dp[SIZE];
bool flag_sumk[SIZE];

int dfs1(int now, int back=-1){
  vector<int> vec1;
  vector<int> vec2;
  int sum_vec1 = 0;
  
  for(int i=0;i<G[now].size();i++){
    if(G[now][i] == back) continue;

    int res = dfs1(G[now][i], now);

    vec1.push_back(sumk[G[now][i]] >= 1);
    sum_vec1 += sumk[G[now][i]] >= 1;
    vec2.push_back(res);
    
    sum[now] += sum[G[now][i]];
    sumk[now] += sumk[G[now][i]] >= 1;
  }

  int maxSum = sum_vec1;
  
  for(int i=0;i<vec1.size();i++){
    maxSum = max(maxSum, sum_vec1 - vec1[i] + vec2[i]);
  }

  sum[now]++;

  if(sum[now] >= k && sumk[now] == 0){
    sumk[now] = 1;
    flag_sumk[now] = true;
    //maxSum = max(maxSum, 1);
  }

  dp[now] = maxSum;
  return maxSum;
}

int dfs2(int now, int back = -1, int prev_sumk = -INF){
  int ans = 0;
  int chisum = 0;
  vector<int> vec;
  int chisumk = 0;
  
  bool flag = false;
  for(int i=0;i<G[now].size();i++){
    if(G[now][i] == back) continue;
    chisum += sum[G[now][i]];
    chisumk += sumk[G[now][i]] >= 1;
    vec.push_back(dp[G[now][i]] - (sumk[G[now][i]] >= 1));
    flag |= sumk[G[now][i]] >= 1 && !flag_sumk[G[now][i]];
  }

  vec.push_back(0);
  vec.push_back(0);
  sort(vec.begin(), vec.end(), greater<int>());

  ans = max(ans, vec[0] + chisumk + prev_sumk);

  if(flag)
    ans = max(ans, vec[0] + vec[1] + chisumk + (n-1-chisum >= k));
  
  for(int i=0;i<G[now].size();i++){
    if(G[now][i] == back) continue;
    ans = max(ans, dfs2(G[now][i], now, sumk[now] - !!sumk[G[now][i]] + ((n-1-chisum) >= k) - flag_sumk[now]));
  }

  
  return ans;
}

int main(){
  int u,v;
  
  scanf("%d%d",&n,&k);

  for(int i=0;i<n-1;i++){
    scanf("%d%d",&u,&v);
    u--; v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  dfs1(0);

  cout << dfs2(0) << endl;
  
  return 0;
}