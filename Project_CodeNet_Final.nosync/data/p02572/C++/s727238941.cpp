#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int64_t> A(N+1);
  for (int i = 1; i < N+1; i++) {
    cin >> A.at(i);
  }
  vector<int64_t> B(N+2);
  B.at(N+1)=0;
  for (int i=N; i>0; i--){
    B.at(i)=(B.at(i+1)+A.at(i)) % 1000000007;
  }
  int64_t ans=0;
  for (int i=1; i<N; i++){
    ans += (A.at(i) * B.at(i+1));
    ans = ans % 1000000007;
  }
  cout << ans << endl;
}