#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main(){
  ll N, X, M;
  cin >> N >> X >> M;
  vector<ll> next(M, -1);
  vector<bool> visited(M, false);
  ll ret = 0;
  ll A = X;
  ll prev = -1;
  for (ll i=0; i<N; i++){
    if (visited[A]){
      ll sum_tmp = 0;
      ll st = A;
      ll c = 0;
      do {
        sum_tmp += A;
        A = (A * A) % M;
        c++;
      } while(A != st);
      ret += sum_tmp * ((N - i) / c);
      ll rem = (N - i) % c;
      for (ll j=0; j<rem; j++){
        ret += A;
        A = (A * A) % M;
      }
      break;
    }
      
    ret += A;
    visited[A] = true;
    prev = A;
    A = (A * A) % M;
  }
  
  cout << ret << "\n";
  return 0;
}