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

vector<ll> a, p;
ll f(int N, ll X) {
  if (N==0) {
    if (X<=0) return 0;
    else return 1;
  }
  else if (X<=1+a[N-1]) return f(N-1, X-1);
  else return p[N-1]+1+f(N-1, X-2-a[N-1]);
}

int main() {
  int N;
  ll X;
  cin >> N >> X;
  a.assign(N+1, 0);
  p.assign(N+1, 0);
  a[0] = 1, p[0] = 1;
  for (int i=1; i<=N; i++) {
    a[i] = 2*a[i-1]+3;
    p[i] = 2*p[i-1]+1;
  }
  cout << f(N, X) << endl;
  return 0;
}