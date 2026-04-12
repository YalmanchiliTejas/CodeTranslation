#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int64_t> vec(N);
  for (int i = 0; i < N; i++){
    cin >> vec.at(i);
  }
  int64_t sum = 0;
  int64_t SUM = 0;
  for (int i = 0; i < N; i++){
    sum += (vec.at(i) % 1000000007);
    sum %= 1000000007;
  }
  for (int i = 0; i < N; i++){
    SUM += ((vec.at(i) % 1000000007) * (vec.at(i) % 1000000007)) % 1000000007;
    SUM %= 1000000007;
  }
  int64_t ans;
  if((sum * sum - SUM) % 2 == 1){
    ans = ((1000000007 + sum * sum - SUM) / 2) % 1000000007;
  }
  else if(sum * sum - SUM < 0){
    ans = ((2000000014 + sum * sum - SUM) / 2) % 1000000007;
  }
  else{
  	ans = ((sum * sum - SUM) / 2) % 1000000007 ;
  }
  cout << ans << endl;
}