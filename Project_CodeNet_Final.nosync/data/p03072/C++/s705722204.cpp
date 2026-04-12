#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1e18

using namespace std;

int main(void){
  ll n;
  cin >> n;
  
  ll ans = 0;
  vector<ll> h(n);
  for (int i = 0; i < n; i++){
    cin >> h[i];
  }
  
  for (int i = 0; i < n; i++){
    int ok = 1;
    for (int j = 0; j < i; j++){
      if (h[i] < h[j])
        ok = 0;
    }
    if (ok)
      ans++;
  }
  
  cout << ans << endl;

  return 0;
}
