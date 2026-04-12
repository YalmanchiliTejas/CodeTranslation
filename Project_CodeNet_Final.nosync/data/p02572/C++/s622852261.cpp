#include <bits/stdc++.h>
using namespace std;



int main() {
  long long M = 1000000007;
  int N;
  long long K=0;
  long long ans = 0;
  cin >> N;
  vector<long> A(N); cin >> A.at(0);
  for(int i=1;i<N;++i){
    cin >> A.at(i);
    K += A.at(i);
  }

  for(int i=0;i<N-1;++i){
    ans += ((K % M) * A.at(i)) % M;
    K -= A.at(i+1);
  }
  cout << ans % M << endl;
  return 0;
}
