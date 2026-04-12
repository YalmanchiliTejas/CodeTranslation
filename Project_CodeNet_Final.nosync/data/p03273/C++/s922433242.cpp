#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;

int main(){
  int h, w;
  cin >> h >> w;
  vector<string> a(h);
  rep(i,h) cin >> a.at(i);
  
  vi x(h), y(w);
  rep(i,h){
    int cnt = 0;
    rep(j,w){
      if (a.at(i).at(j) == '.') cnt++;
    }
    if (cnt != w) x.at(i) = 1;
  }
  rep(i,w){
    int cnt = 0;
    rep(j,h){
      if (a.at(j).at(i) == '.') cnt++;
    }
    if (cnt != h) y.at(i) = 1;
  }
  
  rep(i,h){
    rep(j,w){
      if (x.at(i) == 1 && y.at(j) == 1) cout << a.at(i).at(j);
    }
   if (x.at(i) == 1) cout << endl;
  }
  return 0;
}
