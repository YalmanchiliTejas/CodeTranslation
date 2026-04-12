#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;
constexpr ll mod = 998244353;

int main(){
  int h, w;
  cin >> h >> w;
  int cnt = 0;

  rep(i,h) rep(j,w) {
    char c;
    cin >> c;
    if (c == '#') cnt++;
  }
  if (cnt == h + w - 1) cout << "Possible" << endl;
  else cout << "Impossible" << endl;
  return 0;
} 