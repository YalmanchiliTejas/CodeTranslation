#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


void solve(long long N, long long X, long long M){
  vector<ll> seen(M, -1);

  vector<ll> s;
  while(seen[X] == -1) {
    seen[X] = s.size();
    s.push_back(X);
    X = (X * X) % M;
  }

  ll rv = 0;
  for (ll i = 0; i < seen[X] && N > 0; ++i) {
    rv += s[i];
    N--;
  }

  ll cl = s.size() - seen[X];
  vector<ll> pss(cl);
  partial_sum(s.begin()+seen[X], s.end(), pss.begin());
  ll S = *pss.rbegin();

  rv += S * (N / cl);
  if (N % cl != 0) {
    rv += pss[(N % cl)-1];
  }

  cout << rv << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long N;
  std::cin >> N;
  long long X;
  std::cin >> X;
  long long M;
  std::cin >> M;
  solve(N, X, M);
  return 0;
}
