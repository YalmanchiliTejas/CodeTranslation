#include<bits/stdc++.h>
using namespace std;
using ll = long long;


int main(){
  ll N, P = 1000000000 + 7;; 
  cin >> N;
  vector<ll> A(N), XA(N+1);
  for(ll i = 0; i < N; i++){
    cin >> A[i];
    XA[i+1] = XA[i] + A[i];
  }
  ll ans = 0;
  for(ll i = 0; i < N - 1; i++) {
    ans += (A[i] * ((XA[N] + P - XA[i+1]) % P)) % P;
    ans = ans % P;
  }
  cout <<ans << endl;
}
