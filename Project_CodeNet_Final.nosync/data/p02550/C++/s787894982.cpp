#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main () {
  ll N, X, M;
  cin >> N >> X >> M;
  vector<ll>cycle;
  ll fl = X;
  cycle.push_back(X);
  fl = (fl * fl) % M;
  vector<bool>ex((int)M, false);
  ex[(int)X] = true;
  while (!ex[(int)fl]) {
    ex[(int)fl] = true;
    cycle.push_back(fl);
    fl = (fl * fl) % M;
  }
  int st = 0;
  while (cycle[st] != fl) st ++;
  ll si  = (ll)cycle.size() - (ll)st;
  vector<ll>sum((int)si);
  sum[0] = cycle[st];
  for (int i = 1; i < (int)si; i ++) {
    sum[i] = sum[i - 1] + cycle[i + st];
  }
  ll ans = 0;
  for (int i = 0; i < (int)min((ll)st, N); i ++) {
    ans += cycle[i];
  }
  N -= st;
  if (N <= 0) {
    cout << ans << endl;
    return 0;
  }
  ans += ((N - 1) / si) * sum[(int)(si) - 1];
  ans += sum[(int)((N - 1) % si)];
  cout << ans << endl;
}
