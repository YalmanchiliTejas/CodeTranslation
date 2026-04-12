#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
  int N;
  cin >> N;
  vector<ll> a(N);
  
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  
  sort(a.begin(), a.end());
  
  ll ans = 0;
  if (N % 2) {
    ll x = 0, y = 0;
    
    for (int j = N-1; j >= N/2 + 2; j--) {
      x += 2 * a[j];
    }
    x += a[N/2+1] + a[N/2];
    for (int j = 0; j < N/2; j++) {
      x -= 2 * a[j];
    }
    
    
    for (int j = N-1; j >= N/2 + 1; j--) {
      y += 2 * a[j];
    }
    y -= (a[N/2] + a[N/2 -1]);
    for (int j = 0; j < N/2 -1; j++) {
      y -= 2 * a[j];
    } 
    
    
    ans = max(x,y);
  } else {
    for (int j = N-1; j >= N/2 + 1; j--) {
      ans += 2 * a[j];
    } 
    ans += a[N/2];
    ans -= a[N/2 -1];
    for (int j = 0; j < N/2 -1; j++) {
      ans -= 2 * a[j];
    }
  }
  
  cout << ans << endl;
  
}