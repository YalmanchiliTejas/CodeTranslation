#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef pair<int,int> P;

int di[] = {0,1};
int dj[] = {1,0};

int main(){
  int h,w;
  cin >> h >> w;
  
  vector<string> a(h);
  rep(i,h) cin >> a[i];
  
  bool ok = true;
  
  queue<P> q;
  q.emplace(0,0);
  
  vector<vector<bool>> map(h,vector<bool>(w));
  map[0][0] = true;
  while( !q.empty() ){
    int i = q.front().first;
    int j = q.front().second; q.pop();
    bool flag[2]; 
    flag[0]  = false; flag[1] = false;
    rep(dir,2){
      int ni = i + di[dir];
      int nj = j + dj[dir];
      if(ni<0||nj<0||ni>=h||nj>=w) continue;
      if(a[ni][nj] == '.') continue;
      flag[dir] = true;
      map[ni][nj] = true;
      q.emplace(ni,nj);
    }
    if(flag[0] && flag[1]) ok = false;
  }
  
  rep(i,h) rep(j,w){
    if(a[i][j] == '#') ok &= map[i][j];
  }
  
  cout << ( ok ? "Possible" : "Impossible" ) << endl;
  
  return 0;
}