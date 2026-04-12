#include<iostream>
using namespace std;

int main() {
  int DIV = 998244353;
  int N, S; cin >> N >> S;
  int A[N]; for (int i = 0; i < N; i++) cin >> A[i];
  int D[S+1]; D[0] = 1;
  for (int i = 1; i <= S; i++) D[i] = 0;
  for (int i = 0; i < N; i++) {
    for (int j = S-A[i]; j >= 0; j--) {
      long n = D[j];
      if (j == 0) n = i+1;
      if (j + A[i] == S) n *= N-i;
      D[j+A[i]] = (D[j+A[i]] + n) % DIV;
    }
  }
  cout << D[S] << endl;
}