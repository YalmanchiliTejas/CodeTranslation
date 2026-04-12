#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long long N;
  cin >> N;
  long long ans = 0;
  long long sum_vec = 0;

  vector<long long> A(N);
  for(int i=0;i<N;i++){
    cin >> A.at(i);
    ans += sum_vec * A.at(i);
    ans %= 1000000007;

    sum_vec += A.at(i);
    sum_vec %= 1000000007;

  }

  cout << ans << endl;
}