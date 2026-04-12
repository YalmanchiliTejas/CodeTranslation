#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <math.h>
#include <cassert>
#define rep(i,n) for(int i = 0; i < n; ++i )
using namespace std;
using ull = unsigned long long;
using P = pair<int,int>;

const int N_MAX = 500;
int n;
vector<int> c[2];
int v [2][N_MAX];

int res[N_MAX][N_MAX];
void flip(){ rep(i,n)rep(j,i) swap(res[i][j],res[j][i]); }
bool func(){
  rep(i,n)rep(j,n) res[i][j] = -1;
  
  rep(x,2){
    rep(i,n){
      int d = v[x][i];
      if(c[x][i] == d) continue;

      rep(j,n){
        if(res[i][j] == !d) return false;
        res[i][j] = d;
      }
    }
    flip();
  }
  
  rep(xx,2)rep(x,2){
    rep(i,n){
      int d = v[x][i];
      if(c[x][i] != d)continue;

      vector<int> js; bool find = false;
      rep(j,n) {
        if(res[i][j]==-1) js.push_back(j);
        if(res[i][j]==d) find = true;
      }
      if(find) continue;
      if(js.size()==0) return false;
      if(js.size()==1) res[i][js[0]] = d;
    }
    flip();
  }
  vector<int> is, js;
  rep(i,n) {
    bool filled = true;
    rep(j,n) if (res[i][j] == -1) filled = false;
    if (!filled) is.push_back(i);
  }
  rep(j,n) {
    bool filled = true;
    rep(i,n) if (res[i][j] == -1) filled = false;
    if (!filled) js.push_back(j);
  }
  rep(i,is.size())rep(j,js.size()) {
    res[is[i]][js[j]] = (i+j)%2;
  }
  return true;
}

ull ans[N_MAX][N_MAX];
int main() {
  cin >> n;
  vector<ull> vs[2];
  rep(i,2) {
    c[i] = vector<int>(n);
    rep(j,n) cin >> c[i][j];
  }
  rep(i,2) {
    vs[i] = vector<ull>(n);
    rep(j,n) cin >> vs[i][j];
  }

  rep(b,64){
    rep(x,2)rep(i,n) v[x][i] = vs[x][i]>>b&1;
    if(!func()){
      cout << -1 << endl;
      return 0;
    }
    rep(i,n)rep(j,n) ans[i][j] |= ull(res[i][j])<<b;
  }
  rep(i,n){
    rep(j,n) cout << ans[i][j] << " ";
    cout << endl;
  }
}
