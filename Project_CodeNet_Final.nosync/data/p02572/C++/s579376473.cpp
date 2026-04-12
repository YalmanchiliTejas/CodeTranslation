#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
const long long INF = 1ll << 60;



int main() {
  ll MOD = 1000000007;
  ll N; cin >> N;
  
  vector<ll> A(N,0);
  ll Aadd = 0;
  rep(i,N){
    cin >> A[i];
    Aadd += A[i];
  }
  sort(A.begin(), A.end());
  ll sum = 0;
  for(ll i = 0; i < N-1; i++){
    Aadd -= A[i];
    sum += ((A[i] % MOD) * (Aadd % MOD)) %MOD;
    sum %= MOD;
  } 
  cout << sum << endl;
	return 0;
}

