#include<iostream>
using namespace std;

int main() {
  int N; cin >> N;
  int A[N]; for (int i = 0; i < N; i++) cin >> A[i];
  long C1[(N+1)/2+1], C2[N/2+1], max_sum[N/2+1];
  C1[0] = C2[0] = max_sum[0] = 0;
  for (int i = 0; i < N; i++) {
    if (i % 2 == 0)
      C1[i/2+1] = C1[i/2] + A[i];
    else
      C2[i/2+1] = C2[i/2] + A[i];
  }
  for (int i = 0; i < N/2; i++)
    max_sum[i+1] = max(max_sum[i] + A[2*i+1], C1[i+1]);
  if (N % 2 == 0) cout << max_sum[N/2] << endl;
  else {
    long max_s = -(1L<<60);
    for (int i = 0; i <= N/2; i++) {
      max_s = max(max_s, max_sum[i] + (C1[N/2+1] - C1[i+1]));
    }
    cout << max_s << endl;
  }
}
