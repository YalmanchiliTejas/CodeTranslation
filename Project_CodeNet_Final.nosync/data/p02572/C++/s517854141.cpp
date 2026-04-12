#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  unsigned long long int A[N];
  for (int i=0; i<N; i++) {
    cin >> A[i];
  }
  unsigned long long int sum = 0ull;
  unsigned long long int sum_j = 0ull;
  for (int j=1; j<N; j++) {
    sum_j = (sum_j + A[j]) % 1000000007ull;
  }
  for (int i=0; i<N-1; i++) {
    sum = (sum + A[i] * sum_j) % 1000000007ull;
	sum_j = (sum_j - A[i+1] + 1000000007ull) % 1000000007ull;
  }
  cout << sum;
  return 0;
}