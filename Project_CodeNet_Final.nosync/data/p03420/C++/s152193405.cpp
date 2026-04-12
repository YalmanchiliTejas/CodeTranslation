#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const ll Mod = 998244353;
const int MAX = 510000;
const double PI = 3.14159265358979;
const vector<int> dx = {1, 0};
const vector<int> dy = {0, 1};

int main() {
  ll N, K;
  cin >> N >> K;
  ll res = 0;
  if (K==0) {
    cout << N*N << endl;
    return 0;
  }
  for (int b=K+1; b<=N; b++) {
    res += (b-K)*(N/b);
    if (N%b>=K) res += N%b-K+1;
  }
  cout << res << endl;
  return 0;
}