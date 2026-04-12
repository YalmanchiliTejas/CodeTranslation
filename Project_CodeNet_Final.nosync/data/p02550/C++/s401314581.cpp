#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

long A[100010];

int main() {
  long N, X, M; cin >> N >> X >> M;
  set<int> a_set;
  a_set.insert(A[0] = X);
  int l = 1;
  for (int i = 1; i <= M; i++) {
    A[i] = A[i-1]*A[i-1]%M;
    if (a_set.find(A[i]) != a_set.end()) {
      break;
    }
    a_set.insert(A[i]);
    l++;
  }
  int j = find(A, A+l, A[l]) - A;
  long sum1 = 0, sum2 = 0;
  for (int i = 0; i < min(N, (long)j); i++) sum1 += A[i];
  if (N > j) {
    for (int i = j; i < l; i++) sum2 += A[i];
    sum2 *= (N-j)/(l-j);
    for (int i = 0; i < (N-j)%(l-j); i++) sum2 += A[i+j];
  }
  cout<<sum1+sum2 << endl;
}