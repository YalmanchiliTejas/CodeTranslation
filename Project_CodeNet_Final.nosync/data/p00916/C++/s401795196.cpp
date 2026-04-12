#include <bits/stdc++.h>
#define REP(i, a, n) for(ll i = ((ll) a); i < ((ll) n); i++)
using namespace std;
typedef long long ll;

void dfs(ll y, ll x, vector< vector<bool> > &used, vector<ll> &X, vector<ll> &Y, vector< vector<ll> > &h) {
  if(used[y][x]) return;
  used[y][x] = true;

  ll dd[5] = { 0, -1, 0, 1, 0 };
  REP(i, 0, 4) {
    ll ny = y + dd[i], nx = x + dd[i + 1];
    if(0 <= ny && ny < Y.size() && 0 <= nx && nx < X.size() && h[y][x] == h[ny][nx]) {
      dfs(ny, nx, used, X, Y, h);
    }
  }
}

int main(void) {
  ll N;
  while(cin >> N, N != 0) {
    vector<ll> L(N), T(N), R(N), B(N), X, Y;
    REP(i, 0, N) {
      cin >> L[i] >> T[i] >> R[i] >> B[i];
      X.push_back(L[i]);
      X.push_back(R[i]);
      Y.push_back(B[i]);
      Y.push_back(T[i]);
    }
    X.push_back(-1);
    X.push_back(1000001);
    Y.push_back(-1);
    Y.push_back(1000001);

    sort(X.begin(), X.end());
    X.erase(unique(X.begin(), X.end()), X.end());
    sort(Y.begin(), Y.end());
    Y.erase(unique(Y.begin(), Y.end()), Y.end());

    REP(i, 0, N) L[i] = lower_bound(X.begin(), X.end(), L[i]) - X.begin();
    REP(i, 0, N) R[i] = lower_bound(X.begin(), X.end(), R[i]) - X.begin();
    REP(i, 0, N) B[i] = lower_bound(Y.begin(), Y.end(), B[i]) - Y.begin();
    REP(i, 0, N) T[i] = lower_bound(Y.begin(), Y.end(), T[i]) - Y.begin();

    vector< vector<ll> > h(Y.size(), vector<ll>(X.size()));
    REP(i, 0, Y.size()) REP(j, 0, X.size()) {
      ll p = 0;
      REP(k, 0, N) if(B[k] <= i && i < T[k] && L[k] <= j && j < R[k]) p = p | (1LL << k);
      h[i][j] = p;
    }

    ll ans = 0;
    vector< vector<bool> > used(Y.size(), vector<bool>(X.size(), false));
    REP(i, 0, Y.size()) REP(j, 0, X.size()) if(!used[i][j]) dfs(i, j, used, X, Y, h), ans++;
    cout << ans << endl;
  }
}
