#include<bits/stdc++.h>
#define rep(i, n) for(int (i)=0 ;i <(n); ++(i))
#define REP(i,m,n) for(int (i) = (m); (i) <= (n); ++(i))
#define yorn(f) puts((f)?"Yes":"No")
#define YORN(f) puts((f)? "YES":"NO")
typedef long long ll;
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> h(n);
  rep(i, n) cin >> h[i];
  int cnt = 1;

  for(int i = 1; i<=n-1; i++) {
    int v = h[i];
    bool ok = true;
    for(int j = 0; j <= i; j++) {
      if(v < h[j]) ok = false;
    }
    if(ok) cnt++;
  }
  cout << cnt << endl;
  return 0;
}