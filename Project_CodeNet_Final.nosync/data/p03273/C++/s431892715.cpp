#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int h,w;
  cin >> h>>w;
  vector<string> v(h);
  rep(i,0,h)cin>>v[i];

  vector<bool> hb(h,false), wb(w,false);
  rep(i,0,h){
    int c = 0;
    rep(j,0,w){
      if(v[i][j]=='#')c++;
    }
    if(c==0)hb[i]=true;
  }

  rep(i,0,w){
    int c = 0;
    rep(j,0,h){
      if(v[j][i]=='#')c++;
    }
    if(c==0)wb[i]=true;
  }

  rep(i,0,h){
    if(hb[i])continue;
    rep(j,0,w){
      if(wb[j])continue;
      cout<<v[i][j];
    }
    cout<<endl;
  }
}
