#include <iostream>
#include <algorithm>
#include <set>
#include <string>
using namespace std;

const int kMax = 1048600;
const int kInf = 1000000000;

string S;
int N, Q;
int Qk[150010];

set< int > L, R;
int Tm[kMax], Td[kMax];

void read();
void solve();

void update(int, int, int, int, int, int);
int query(int, int, int, int, int);

int main() {
  read();
  solve();
  return 0;
}

void read() {
  ios::sync_with_stdio(false);

  cin >> N >> Q >> S, S = "#" + S;
  for (int i = 0; i < Q; ++i)
    cin >> Qk[i];
}

void solve() {
  fill(&Tm[0], &Tm[kMax], 0);

  for (int i = 1, s = 0; i <= N; ++i) {
    if (S[i] == '(')
      ++s, L.insert(i);
    else
      --s, R.insert(i);
    update(1, 0, N, i - 1, i, s);
  }

  for (int qi = 0; qi < Q; ++qi) {
    int p = Qk[qi], t;

    if (S[p] == '(') {
      // flip query
      S[p] = ')';
      update(1, 0, N, p - 1, N, -2);
      L.erase(p), R.insert(p);

      // find answer
      t = *R.begin();
      cout << t << "\n";

      // flip answer
      S[t] = '(';
      update(1, 0, N, t - 1, N, 2);
      R.erase(t), L.insert(t);
    }
    else {
      // flip query
      S[p] = '(';
      update(1, 0, N, p - 1, N, 2);
      R.erase(p), L.insert(p);

      // find answer
      int low = 1, up = N, mid;
      while (low < up) {
        mid = (low + up) / 2;
        if (query(1, 0, N, mid - 1, N) >= 2)
          up = mid;
        else
          low = mid + 1;
      }
      t = *L.lower_bound(up);
      cout << t << "\n";

      // flip answer
      S[t] = ')';
      update(1, 0, N, t - 1, N, -2);
      L.erase(t), R.insert(t);
    }
  }
}

void update(int u, int l, int r, int ql, int qr, int qd) {
  if (ql <= l && r <= qr)
    Tm[u] += qd, Td[u] += qd;
  else {
    int mid = (l + r) / 2;

    if (Td[u] != 0) {
      update(2 * u,     l, mid, l, mid, Td[u]);
      update(2 * u + 1, mid, r, mid, r, Td[u]);
      Td[u] = 0;
    }

    if (ql < mid) update(2 * u,     l, mid, ql, qr < mid ? qr : mid, qd);
    if (qr > mid) update(2 * u + 1, mid, r, ql > mid ? ql : mid, qr, qd);

    Tm[u] = min(Tm[2 * u], Tm[2 * u + 1]);
  }
}

int query(int u, int l, int r, int ql, int qr) {
  if (ql <= l && r <= qr)
    return Tm[u];
  else {
    int mid = (l + r) / 2;

    if (Td[u] != 0) {
      update(2 * u,     l, mid, l, mid, Td[u]);
      update(2 * u + 1, mid, r, mid, r, Td[u]);
      Td[u] = 0;
    }

    int ret = kInf;

    if (ql < mid) ret = min(ret, query(2 * u,     l, mid, ql, qr < mid ? qr : mid));
    if (qr > mid) ret = min(ret, query(2 * u + 1, mid, r, ql > mid ? ql : mid, qr));

    return ret;
  }
}