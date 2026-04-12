#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll p=1e9+7;

int main(){
  ll N;
  cin >> N;
  vector<ll> S(N,0);
  vector<ll> A(N);
  for(ll i=0;i<N;i++){
    cin >> A[i];
  }
  S[0]=A[0];
  for(ll i=1;i<N;i++){
    S[i]=A[i]+S[i-1];
  }
  ll ans=0;
  for(ll i=0;i<N;i++){
    ans=(ans+A[i]*((S[N-1]-S[i])%p))%p;
  }
  cout << ans << endl;
}