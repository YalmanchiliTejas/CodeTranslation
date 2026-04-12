#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
typedef long long ll;

int main(){
  int n, m;
  cin >> n >> m;
  int a[n];
  vector<vector<int>> d(n, vector<int>(n, 0));
  rep(i, n) a[i] = i;
  rep(i, m){
    int b, c;
    cin >> b >> c;
    b--, c--;
    d[b][c] = 1, d[c][b] = 1;
  }
  int ans = 0;
  do {
    bool can = true;
    rep(i, n-1){
      if(!d[a[i]][a[i+1]]) can = false;
    }
    if(can) ans++;
  } while(next_permutation(a+1, a+n));
  cout << ans << endl;
  return 0;
}
