#include <bits/stdc++.h>
using namespace std;

int main () {
  int N;
  cin >> N;
  long long sum = 0;
  vector<long long>A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
    sum += A.at(i);
  }
  long long ans = 0;
  
  for (int i = 0; i < N; i++) {
    long long B = ((sum-A.at(i)) % 1000000007) * A.at(i);
    ans += B;
    ans %= 1000000007;
  }
  if (ans % 2 == 0){
    cout << ans/2 << endl;
  }
  else {
    cout << (ans + 1000000007)/2 << endl;
  }
}
  
    