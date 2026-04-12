#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;

int main(){
  int n, q;
  cin >> n >> q;
  int a[q], b[q];
  vector<int> f(n);
  f[0] = 1; f[1] = -1;
  int pos = 0;
  rep(i,q) {
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
    if(f[a[i]] == 1) pos = b[i];
    if(f[b[i]] == 1) pos = a[i];
    swap(f[a[i]],f[b[i]]);
    if(pos+1 < n and f[pos+1] == 0) f[pos+1] = -1; 
    if(pos-1 >= 0 and f[pos-1] == 0) f[pos-1] = -1; 
  }
  int ans = 0;
  rep(i,n) if(f[i] != 0) ans++;
  cout << ans << endl;
  return 0;
}
