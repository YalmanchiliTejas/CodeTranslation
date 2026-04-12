#include <bits/stdc++.h>
using namespace std;
int main(){
  string k; int d; cin >> k >> d;
  int lk = k.size();
  vector<vector<vector<int> > > f(2, vector<vector<int> > (lk + 1, vector<int> (d, 0) ) );
  f[1][lk][0] = 1;
  f[0][lk][0] = 1;
  const int mod = 1000000007;
  for(int i = lk - 1; i >= 0; i--){
    for(int rot = 0; rot < 2; rot++){
      for(int j = 0; j < d; j++){
        int lim = rot ? 9 : (k[i] - '0');
        for(int dig = 0; dig <= lim; dig++){
          f[rot][i][j] += f[rot || (dig < lim)][i + 1][(j + dig)%d];
          if(f[rot][i][j] >= mod) f[rot][i][j] -= mod;
        }
      }
    }
  }
  int ans = f[0][0][0] + mod - 1;
  if(ans >= mod) ans -= mod;
  cout << ans << endl;
  return 0;
}
          
  
  
