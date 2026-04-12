#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

typedef pair<int,int> PII;
typedef pair<int,PII> PIII;

int ufind(vector<int>& P, int u) {
  if (P[u] == 0) {
    return u;
  }
  return P[u] = ufind(P, P[u]);
}

void uf(vector<int>& P, int u, int v) {
  int _u = ufind(P, u);
  int _v = ufind(P, v);
  if (_u != _v) {
    P[_u] = _v;
  }
}

int main()
{
  int n;
  vector<PII> X, Y;

  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int x,y;
    cin >> x >> y;
    X.push_back(make_pair(x,i));
    Y.push_back(make_pair(y,i));
  }

  sort(X.begin(), X.end());
  sort(Y.begin(), Y.end());

  vector<PIII> q;
  for (int i = 1; i < n; ++i) {
    int u = X[i-1].second, v = X[i].second;
    int xu = X[i-1].first, xv = X[i].first;
    q.push_back(make_pair(xv-xu, make_pair(u,v)));
  }
  for (int i = 1; i < n; ++i) {
    int u = Y[i-1].second, v = Y[i].second;
    int yu = Y[i-1].first, yv = Y[i].first;
    q.push_back(make_pair(yv-yu, make_pair(u,v)));
  }
  sort(q.begin(), q.end());

  long long res = 0;
  vector<int> P(n+1);
  for (PIII p : q) {
    int d = p.first;
    int u = p.second.first, v = p.second.second;

    if (ufind(P, u) != ufind(P, v)) {
      res += d;
      uf(P, u, v);
    }
  }
  cout << res << "\n";
}
