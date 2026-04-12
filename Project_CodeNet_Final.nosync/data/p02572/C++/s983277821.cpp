#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

int main(void) {
  long long i, tmp, sum_A, answer;
  long long N, CONST_VAL;
  vector<long long> A;
  
  CONST_VAL = 1000000007;
  // get input
  cin >> N;
  for(i = 0; i < N; i++) {
    cin >> tmp;
    A.push_back(tmp);
  }
  // calc answer
  answer = 0;
  sum_A = 0;
  for(i = A.size() - 1; i >= 1; i--) {
    sum_A = (sum_A + A[i])%CONST_VAL;
    answer = (answer + A[i - 1]*sum_A)%CONST_VAL;
  }
  
  // disp answer
  cout << answer << endl;
  
  return 0;
}
