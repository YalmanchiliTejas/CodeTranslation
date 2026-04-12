#include <bits/stdc++.h>
using namespace std;

#define PI 3.14159265359

int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  int64_t sum = 0;
  for (int i = 0; i < N; i++){
    cin >> A[i];
    sum = (sum + A[i]) % 1000000007;
  }
  int64_t ans = 0;
  for (int i = 0; i < N; i++){
    if (sum - A[i] > 0) sum = sum - A[i];
    else sum = 1000000007 + sum - A[i];
    ans = (ans + sum * A[i]) % 1000000007;
  }
  cout << ans << endl;
}
