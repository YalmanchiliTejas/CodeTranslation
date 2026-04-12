#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1e18
#define PI 3.14159265358979

using namespace std;

int main(void){
  ll n, m;
  cin >> n >> m;
  
  vector<vector<int>> mat(n, vector<int>(n, 0));
  for (int i = 0; i < m; i++){
    ll a, b;
    cin >> a >> b;
    a--; b--;
    mat[a][b] = 1;
    mat[b][a] = 1;
  }
  int c[8] = {0, 1, 2, 3, 4, 5, 6, 7};
  ll res = 0;
  do {
    int ok = 1;
    for (int i = 0; i < n - 1; i++){
      if (mat[c[i]][c[i+1]] == 0)
        ok = 0;
    }
    if (ok)
      res++;
  } while (next_permutation(c + 1, c + n));

  cout << res << endl;

  return 0;
}
