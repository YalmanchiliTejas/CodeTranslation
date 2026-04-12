#include <bits/stdc++.h>

#define inf 0x3f3f3f3f
#define pb push_back
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector <int> vi;
typedef vector <ll> vl;
typedef vector <ull> vu;
typedef vector <vector <int>> vvi;
typedef pair <int, int> pi;
typedef vector <pair <int, int>> vpi;

int h, w;

char a[101][101];

bool lin[101], col[101];

void read() {
  cin >> h >> w;
  for(int i = 0; i < h; ++i)
    for(int j = 0; j < w; ++j) {
      cin >> a[i][j];
      if (a[i][j] == '#') {
        lin[i] = 1;
        col[j] = 1;
      }
    }
}

void solve() {
  for(int i = 0; i < h; ++i) {
    if (!lin[i])
      continue;
    for(int j = 0; j < w; ++j) {
      if (!col[j])
      continue;
      cout << a[i][j];
    }
    cout << "\n";
  }
}

int main() {
  ios :: sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  //cin >> t; //please do not forget to comment this if there are no queries
  while(t) {
    --t;
    read();
    solve();
  }
  return 0;
}
