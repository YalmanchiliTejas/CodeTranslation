#include <bits/stdc++.h>
using namespace std;
int main () {
  long N;
  cin >> N;
  vector<long> data(N), sub(N);
  long sum = 0;
  for(int i = 0; i < N; i++){
    cin >> data.at(i);
  }
  sub.at(N - 1) = data.at(N - 1);
  for(int i = N - 2; i >= 0; i--){
    sub.at(i) = sub.at(i + 1) + data.at(i);
  }
  long ans = 0, a;
  for(int i = 0; i < N; i++){
    a = sub.at(i) - data.at(i);
    a %= 1000000007;
    ans += a * data.at(i);
    ans %= 1000000007;
  }
  cout << ans << endl;
  return 0;
}