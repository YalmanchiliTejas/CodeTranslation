#include<iostream>
using namespace std;

int main() {
  int DIV = 1e+9 + 7;
  int N; cin >> N;
  int A[N];
  for (int i = 0; i < N; i++) cin >> A[i];
  long sum = 0, sq_sum = 0;
  for (int i = 0; i < N; i++) {
    sum = (sum+A[i]) % DIV;
    sq_sum = (sq_sum + (long)A[i]*A[i]%DIV) % DIV;
  }
  int resx2 = (sum*sum-sq_sum)%DIV;
  if (resx2 % 2 == 0) cout << resx2/2 << endl;
  else cout << (resx2+DIV)/2 << endl;
}