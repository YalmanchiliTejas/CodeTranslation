#include "iostream"
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <cstring>
#include <math.h>
#include <cctype>
#include <stack>
#include <vector>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <iomanip>
using namespace std;
using ll=long long;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define MOD  1000000007
int dx[4]={0,0,-1,1},dy[4]={1,-1,0,0};

int N,M,ans;
bool visited[10];
int G[10][10];

void dfs(int from, int cnt){
  if(cnt==N){
    ans++;
    return;
  }

  visited[from]=1;
  for(int i=0; i<N; i++) if(!visited[i] && G[from][i]) dfs(i,cnt+1);
  visited[from]=0;

}

int main(int argc, char const *argv[]) {
  std::cin >>  N >> M;
  for(int i=0; i<M; i++){
    int a,b; std::cin >> a >> b;
    G[a-1][b-1]=G[b-1][a-1]=1;
  }

  dfs(0,1);
  std::cout << ans << '\n';
  return 0;
}
