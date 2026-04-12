#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int N;
  cin >> N;
  vector<ll> A(200005);
  rep(i,N) cin >> A[i];
  vector<ll> S(200005);
  S[0] = A[0];
  for(int i = 0; i < N-1; i++){
    S[i+1] = S[i] + A[i+1]; 
  }
  ll sum = 0;
  ll mod = 1000000000+7;
  rep(i,N-1){
    ll a = (S[N-1]-S[i])%mod;
    sum += A[i]*a;
    sum %= mod;
  }
  cout << sum << endl;
  return 0;
}
