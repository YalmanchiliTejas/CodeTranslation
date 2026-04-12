#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define FOR(i, a, b) for (int i=(a); i<(b); i++)
using Graph = vector<vector<int>>;
int main() {
  int N;
  cin >> N;
  long long sum = 0;
  long long sum2 = 0;
  FOR(i,0,N) {
    long long x;
    cin >> x;
    sum += x;
    sum %= 1000000007;
    sum2 += (x*x)%1000000007;
    sum2 %= 1000000007;
  }
  long long A = (sum*sum) % 1000000007;
  while (A < sum2) {
    A += 1000000007;
  }
  cout << (((A - sum2)%1000000007) * 500000004) % 1000000007 << endl;
      
  return 0;
}