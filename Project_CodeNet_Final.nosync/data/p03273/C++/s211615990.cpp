#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
using namespace std;
using ll = long long;
using P = pair<int, int>;
 
int main() {
  int h,w;
  cin >>  h >> w;
  vector<vector<char>> a(h,vector<char>(w));
  rep(i,h){
    rep(j,w)cin >> a[i][j];
  }
  set<int> sh;
  set<int> sw;
  rep(i,h){
    bool check = false;
    rep(j,w){
      if(a[i][j] == '#') check = true;
    }
    if(!check) sh.insert(i);
  }
  rep(i,w){
    bool check = false;
    rep(j,h){
      if(a[j][i] == '#') check = true;
    }
    if(!check) sw.insert(i);
  }
  
      
  rep(i,h){
    rep(j,w){
      if(sh.count(i) || sw.count(j))continue;
      cout << a[i][j];
    }
    if(!sh.count(i)) cout << endl;
  }
  
}

