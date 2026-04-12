#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
typedef long long ll;
typedef pair<int,int> P;

int main(){
  int h,w;
  cin >> h >> w;
  vector<vector<char>> g(h,vector<char>(w));
  rep(i,h)rep(j,w)cin >> g[i][j];
  vector<bool> row(h,0);
  vector<bool> col(w,0);
  rep(i,h)rep(j,w)if(g[i][j]=='#'){
    row[i]=1;
    col[j]=1;
  }
  rep(i,h){
    if(!row[i])continue;
    rep(j,w){
      if(!col[j])continue;
      cout << g[i][j];
    }
    cout << endl;
  }
}