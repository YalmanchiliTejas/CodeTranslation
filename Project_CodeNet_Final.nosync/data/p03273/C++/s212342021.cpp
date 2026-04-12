#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;
const int N = (int)2e5 + 3;

typedef long long ll;
typedef long double ld;

typedef pair < ll, ll > pll;
typedef pair < int, int > pii;

int n, m, used[101], used2[101];
char a[101][101], ans[101][101];
int main(){
  cin >> n >> m;
  for (int i = 1; i <= n; ++i){
    int ok = 1;
    for (int j = 1; j <= m; ++j){
      cin >> a[i][j];
      if (a[i][j] == '#') ok = 0;
    }
    if (ok){
      used[i] = 1;
    }
  }
  for (int i = 1; i <= m; ++i){
    int ok = 1;
    for (int j = 1; j <= n; ++j){
      if (a[j][i] == '#') ok = 0;
    }
    if (ok == 1){
      used2[i] = 1;
    }
  }
  //cout << "\n";
  for (int i = 1; i <= n; ++i){
    if (used[i]) continue;
    for (int j = 1; j <= m; ++j){
      if (used2[j]) continue;
      cout << a[i][j];
    }
    cout << "\n";
  }
  return 0;
}
