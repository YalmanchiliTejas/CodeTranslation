#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

ll dp[3100][3100];
bool memo[3100][3100];

ll f(const vector<ll> &v, int x, int y) {
  if(memo[x][y]) return dp[x][y];
  memo[x][y] = true;
  if(x==y) dp[x][y]=v.at(x);
  else {
    dp[x][y] = max(v.at(x)-f(v,x+1,y), v.at(y)-f(v,x,y-1));
  }
  return dp[x][y];
}

int main() {
  int N;
  cin >> N;
  vector<ll> v(N);
  for (int i = 0; i < N; i++) {
    cin >> v.at(i);
  }
  for (int i = 0; i < N-1; i++) {
    memo[i][i+1] = true;
    dp[i][i+1] = abs(v.at(i) - v.at(i+1));
  }
  cout << f(v,0,N-1) << endl;
}
  