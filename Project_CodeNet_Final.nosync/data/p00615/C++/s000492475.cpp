#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
  int n, m;
  while(cin >> n >> m, n || m){
    ll d[20000];
    for(int i = 0; i < n+m; i++) cin >> d[i];
    sort(d, d + n+m);
    ll ans = d[0];
    for(int i = 1; i < n+m; i++){
      ans = max(ans, d[i] - d[i-1]);
    }
    cout << ans << endl;
  }
  return 0;
}