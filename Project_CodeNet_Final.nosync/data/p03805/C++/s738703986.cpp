#include <bits/stdc++.h>

#define foreach(i, v) for(__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++ i)
#define BETWEEN(a, x, b) (a<=x&&x<b)

using namespace std;
typedef long long ll;

int gr[10][10];
int n,m;
int vis[10];

int solve(int p, int depth) {
  if (depth == n){
    return 1;
  }
  vis[p] = 1;
  int res = 0;
  for(int i=0;i<n;i++){
    if(i==p)continue;
    if(gr[p][i] && !vis[i]){
      res += solve(i, depth+1);
    }
  }
  vis[p] = 0;
  return res;
}

int main(int argc, char *argv[]) { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  cin>>n>>m;
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    a--,b--;
    gr[a][b]=1;
    gr[b][a]=1;
  }

  int res = solve(0, 1);
  cout<<res<<endl;

  return 0;
}
