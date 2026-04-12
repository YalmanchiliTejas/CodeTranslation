// abco54c: One-stroke Path
#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

#define rep(i,n) for(int i=0;i<(n);i++)
#define in(x) cin>>(x)
#define oute(x) cout<<(x)<<endl

int n,m;
vvi v(8);
vi visit(8);

void dfs(int p, int c, int distance, int &count){
  if(distance==n-1){
    count++;
    return;
  }
  visit[c] = true;
  for(auto cc:v[c]){
    if(visit[cc]) continue;
    dfs(c,cc,distance+1,count);
  }
  visit[c] = false;
}

int main(){
  in(n);in(m);
  rep(i,m){
    int a,b; in(a);in(b);
    a--; b--;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  int count = 0;
  dfs(-1,0,0,count);
  oute(count);
}