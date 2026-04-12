#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i=(a); i<(b); i++)
#define RFOR(i, a, b) for(int i=(a); i>=(b); i--)
#define rep(i, n) FOR(i, 0, n)
#define rrep(i, n) RFOR(i, n, 0)
#define dump(x)  cout << #x << " = " << (x) << endl;

typedef long long ll;
typedef pair<int, int> ii;
const ll INF = 1e18;
const int inf = 1e8;


void solve()
{
  int h,w; cin>>h>>w;
  vector<string> a(h);
  rep(i,h) cin>>a[i];
  vector<int> x(w, 0);
  vector<int> y(h, 0);
  for (int i=0; i<h; i++) {
    for (int j=0; j<w; j++) {
      if (a[i][j]=='#') {
        x[j]=1;
        y[i]=1;
      }
    }
  }
  for (int i=0; i<h; i++) {
    if (y[i]==0)continue;
    for (int j=0; j<w; j++) {
      if (x[j]==0)continue;
      cout<<a[i][j];
    }
    cout<<endl;
  }
}

int main()
{
  solve();
  return 0;
}
