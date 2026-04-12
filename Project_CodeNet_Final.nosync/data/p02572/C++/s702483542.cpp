#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t N;
  cin >> N;
  int64_t ans, sum;
  ans =0;
  sum =0;
  vector<int>A(N);
  for(int i=0; i<N; i++){
    cin >> A.at(i);
    sum += A.at(i);
  }
  
  for(int i=0; i<N; i++){
    sum-= A.at(i);
    ans += A.at(i)*(sum%1000000007);
    ans %= 1000000007;
  }
  
  cout << ans <<endl;
  
  
  
  
}
