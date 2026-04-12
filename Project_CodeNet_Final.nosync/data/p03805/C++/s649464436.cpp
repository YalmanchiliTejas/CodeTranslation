#include <bits/stdc++.h>

#define INF 10000001

#define MOD 1000000007

typedef long long ll;

std::map<int,std::vector<int>> mp;
std::vector<int> used;
std::vector<std::vector<int>> connect;

int dfs(int now,int depth,int n){
  if(used[now]){
    return 0;
  }
  if(depth==n){
    return 1;
  }

  used[now] = 1;

  int ans = 0;
  for(int i=0;i<n;i++){
    if(connect[now][i]){
      ans += dfs(i,depth+1,n);
    }
  }

  used[now] = 0;

  return ans;
}

int main(void){
  int n,m,a,b;
  std::cin >> n >> m;

  used = std::vector<int>(n,0);
  connect = std::vector<std::vector<int>>(n,std::vector<int>(n,0));
  for(int i=0;i<m;i++){
    std::cin >> a >> b;
    a -= 1; b -= 1;
    connect[a][b] = connect[b][a] = 1;
  }

  std::cout << dfs(0,1,n) << std::endl;
  return 0;
}
