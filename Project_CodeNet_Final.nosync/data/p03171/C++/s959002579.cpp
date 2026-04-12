#include <bits/stdc++.h>
using namespace std;
int main(){
  int n; cin >> n;
  vector<int> a(n); for(int & i : a) cin >> i;
  vector<vector<long long> > f(n, vector<long long>(n, 0));
  for(int i = 0; i < n; i++) 
    if(n&1) f[i][i] = a[i];
  	else f[i][i] = -a[i];
  for(int i = 2; i <= n; i++){
    for(int j = 0; j <= n - i; j++){
      if((n - i)%2 == 0){
        f[j][j+i-1] = max(f[j][j+i-2]+a[j+i-1], a[j]+f[j+1][j+i-1]);
      } else {
        f[j][j+i-1] = min(f[j][j+i-2]-a[j+i-1], -a[j]+f[j+1][j+i-1]);
      }
    }
  }
  cout << f[0][n-1] << endl;
  return 0;
}
