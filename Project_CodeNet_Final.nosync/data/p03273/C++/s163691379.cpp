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
  vector<string> a(h);
  rep(i,0,h)cin>>a[i];

  vector<bool> r(h,false),c(w,false);

  rep(i,0,h){
    int count = 0;
    rep(j,0,w){
      if(a[i][j]=='.')count++;
    }
    if(count==w)r[i]=true;
  }
  rep(i,0,w){
    int count = 0;
    rep(j,0,h){
      if(a[j][i]=='.')count++;
    }
    if(count==h)c[i]=true;
  }

  rep(i,0,h){
    if(r[i]) continue;
    rep(j,0,w){
      if(c[j]) continue;
      cout<<a[i][j];
    }
    cout<<endl;
  }
}
