#include <iostream>
#define int long long
using namespace std;

const int N = 3e3;

bool b[N][N];
int n, a[N], val[N][N];

int DFS(int i, int j, int k) {
  if(b[i][j])
    return val[i][j];
  b[i][j] = true;
  if(k < 0)
    val[i][j] = min(DFS(i+1, j, 1) - a[i], DFS(i, j-1, 1) - a[j]);
  else
    val[i][j] = max(DFS(i+1, j, -1) + a[i], DFS(i, j-1, -1) + a[j]);
  return val[i][j];
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
  cin >> n;
  int k = ((n % 2) * 2) - 1;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    b[i][i] = true;
    val[i][i] = a[i] * k;
  }
  cout << DFS(0, n-1, 1);
}