#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF = 1e9;
const int MOD = 1e9 + 7;

int main(){
  int N;
  cin >> N;
  vector<ll> left(N);
  vector<ll> right(N);
  vector<ll> A(N);
  rep(i, N){
    cin >> A.at(i);
  }
  rep(i, N){
    if(i == 0){
      left.at(i) = A.at(i);
      right.at(i) = A.at(i);
    }
    else{
      left.at(i) = (left.at(i - 1) + A.at(i)) % MOD;
      right.at(i) = A.at(i);
    }
  }
  ll sum = 0;
  rep(i, N - 1){
    sum += ((left.at(i) % MOD) * right.at(i + 1) % MOD);
    sum %= MOD;
  }
  cout << sum << endl;
    
}
