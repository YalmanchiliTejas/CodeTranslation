#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<string>
#include<random>
#include<map>
#include<queue>
using namespace std;

int cnt = 0;

int dfs(vector< pair<int, int> > p, vector<bool> b, vector<bool> f, int pos){
  bool ff = true;
  for(int i=0; i<f.size(); i++){
    if( !f[i] ){
      ff = false;
      break;
    }
  }
  if( ff ){
    cnt++;
    return 0;
  }

  for(int i=0; i<p.size(); i++){

    if( pos == p[i].first && !f[p[i].second] ){
      f[p[i].second] = true;
      dfs(p, b, f, p[i].second);
      f[p[i].second] = false;
    }
    if( pos == p[i].second && !f[p[i].first] ){
      f[p[i].first] = true;
      dfs(p, b, f, p[i].first);
      f[p[i].first] = false;
    }

  }

  return 0;
}


int main(){

  int n, m;
  cin >> n >> m;

  vector< pair<int, int> > p(m);
  for(int i=0; i<m; i++){
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    p[i].first = a;
    p[i].second = b;
  }

  vector<bool> b(m, false);
  vector<bool> f(n, false);
  f[0] = true;

  dfs(p, b, f, 0);

  cout << cnt << endl;

  return 0;
}








// EOF
