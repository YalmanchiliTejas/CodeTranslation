#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

const int N = 1e5 + 500;

int dp[N][2],n;
vector < int > v[N];


int f(int i,int x,int lst){
  if(x == 0 && v[i].size() == 1 && i != 1) return 0;
  if(v[i].size() == 1 && i != 1) return 1;
  if(dp[i][x] != -1) return dp[i][x];
  vector < int > v1,v0;
  int s0 = 0,s1 = 0;
  for(int j = 0;j<v[i].size();j++){
    if(v[i][j] == lst) continue;
    v0.push_back(f(v[i][j],0,i));
    v1.push_back(f(v[i][j],1,i));
    s0 += v0[v0.size() - 1];
    s1 += v1[v1.size() - 1];
  }
  if(x == 1 && s0 != v0.size()) return dp[i][x] = 0;
  if(x == 1) return dp[i][x] = 1;
  int tk = 0;
  for(int j = 0;j<v0.size();j++){
    if(v1[j] + s0 - v0[j] == v0.size()) return dp[i][x] = 1;
  }
  return dp[i][x] = 0;
}

int main(){
  memset(dp,-1,sizeof(dp));
  scanf("%d",&n);
  for(int i = 0;i<n-1;i++){
    int a,b;
    scanf("%d%d",&a,&b);
    v[a].push_back(b);
    v[b].push_back(a);
  }
  if(f(1,0,1)) printf("Second\n");
  else printf("First\n");
}
