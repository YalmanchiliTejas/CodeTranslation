#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t N;
  cin >> N;
  int64_t mod = pow(10, 9) + 7;
  vector<int64_t> A(N);
  int64_t S=0, T=0;
  for (int i=0; i<N; i++) {
    cin >> A[i];
    S += (A[i]-A[i]/mod*mod);
    S -= S/mod*mod; 
    T += (A[i]-A[i]/mod*mod)*(A[i]-A[i]/mod*mod);
    T -= T/mod*mod; 
  }
  int64_t SS=S*S;
  SS = SS - SS/mod*mod;
  int64_t M = SS - T;
  if (M<0) {
    M += mod;
  }
  if (M-M/2*2==1) {
    M += mod;
  }
  M/=2;
  
  cout << M << endl;
}