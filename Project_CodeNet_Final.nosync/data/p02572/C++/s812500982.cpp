#include<bits/stdc++.h>
#define ll long long

using namespace std;

void dis(int* As, int N) {
  for (int i = 0; i < N; i++) {
    cout << As[i] << " ";
  }
  cout << endl;
}

int main() {
  int mod = 1e9 + 7;
  
  int N;
  cin >> N;
  ll As[N];
  ll Bs[N+1];
  Bs[0] = 0;
  
  for (int i = 0; i < N; i++) {
    cin >> As[i];
    Bs[i+1] = Bs[i] + As[i];
  }
  
  ll ans = 0;
  for (int i = 0; i < N; i++) {
    ans += (Bs[i]%mod)*As[i];
    ans %= mod;
  }
  cout << ans << endl;
}