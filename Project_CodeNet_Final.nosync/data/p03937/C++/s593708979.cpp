#include<bits/stdc++.h>
using namespace std;

const int N_MAX=10;
bool f[N_MAX][N_MAX];
int h,w;
int cnt=0;

bool dfs(int x, int y, int t) {
  if (x==h-1&&y==w-1&&t==cnt) return true;
  if (f[x+1][y]) return dfs(x+1, y, t+1);
  if (f[x][y+1]) return dfs(x, y+1, t+1);
  return false;
}

int main() {
  cin>>h>>w;
  for (int i=0;i<h;i++) {
    for (int j=0;j<w;j++) {
      char c; cin>>c;
      if (c=='#') f[i][j]=true;
      else f[i][j]=false;
      if (f[i][j]) cnt++;
    }
  }
  if (dfs(0, 0, 1)) cout<<"Possible"<<endl;
  else cout<<"Impossible"<<endl;
}
