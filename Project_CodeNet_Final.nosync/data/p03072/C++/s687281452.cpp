#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{

  int n;
  cin >> n;
  int a[n];
  rep(i,n) cin >> a[i];
  int ans = 1;
  int max = a[0];
  rep(i, n- 1) {
    if(max <= a[i + 1]) {
      ans++;
      max = a[i + 1];
    }
  }
  cout << ans << endl;
  return 0;
}