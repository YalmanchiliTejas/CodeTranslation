#include <bits/stdc++.h>
using namespace std;

#define M 1000000007


int main(){
  int N;
  cin >> N;

  vector<int64_t> A(N);
  for (int n = 0; n < N; n++){
    cin >> A.at(n);
  }

  int64_t a = 0;
  int64_t b;
  int64_t p;
  int64_t sum = 0;
  for (int n = 0; n < N-1; n++){
    a += A.at(n);
    b = A.at(n+1);
    p = ((a % M) * (b % M)) % M;
    sum = (sum + (p % M)) % M;
    //cout << "a:" << a << " b:" << b << " a*b:" << a*b << " part:" << p << endl;
  }

  cout << sum << endl;
  
  return 0;
}
