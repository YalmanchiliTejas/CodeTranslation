#include <cstdio>
#include <cmath>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#include <cassert>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

#define rep(i,a,b) for(int i = a; i < b; i++)
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d%d",&x,&y)
#define P(x) printf("%d\n",x)
#define all(v) v.begin(),v.end()
#define mp make_pair
#define pb push_back
#define FF first
#define SS second

typedef long long int LL;
typedef pair<int, int > pii;
typedef vector<int > vi;

const int N = 100001;
vi g[N];
bool flag;

int dfs(int c, int p) {
  int cnt = 1;
  rep(i,0,g[c].size()) {
    int u = g[c][i];
    if(u != p) {
      cnt += dfs(u, c);
    }
  }
  if(cnt > 2) flag = true;
  return cnt % 2;
}

int main() {
  int n;
  S(n);
  rep(i,0,n-1) {
    int u,v;
    S2(u,v);
    g[u].pb(v);
    g[v].pb(u);
  }
  if(dfs(1,-1) || flag) {
    printf("First\n");
  } else {
    printf("Second\n");
  }
  return 0;
}
