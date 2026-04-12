#include <bits/stdc++.h>

using namespace std;

inline void read() {}
template <class S>
inline void read(S &arg) {
  cin >> arg;
}
template <class S>
inline void readA(S Lptr, S Rptr) {
  while (Lptr != Rptr) {
    read(*Lptr);
    Lptr++;
  }
}
template <class S, class... T>
inline void read(S &arg, T &... rest) {
  read(arg);
  read(rest...);
}

inline void write() {}
template <class S>
inline void write(S arg) {
  cout << arg;
}
template <class S>
inline void writeA(S Lptr, S Rptr) {
  if (Lptr != Rptr) {
    write(*Lptr);
    Lptr++;
  }
  while (Lptr != Rptr) {
    write(' ');
    write(*Lptr);
    Lptr++;
  }
}
template <class S, class... T>
inline void write(S arg, T... rest) {
  write(arg);
  write(' ');
  write(rest...);
}

#define rep(i, j, k) for (int i = j; i < (int)k; i++)
#define pb push_back
#define mt make_tuple
#define all(x) x.begin(), x.end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

template <class T, class S>
inline bool smin(T &a, S b) {
  return (T)b < a ? a = b, 1 : 0;
}
template <class T, class S>
inline bool smax(T &a, S b) {
  return a < (T)b ? a = b, 1 : 0;
}

constexpr int MOD = 1e9 + 7;
constexpr int N = 1e6 + 10;

template <typename T>
inline T mod(T &v) {
  return v = (v % MOD + MOD) % MOD;
}
template <typename S, typename T>
inline S add(S &l, T r) {
  return mod(l += r);
}

ll po(ll v, ll u) {
  return u ? po(v * v % MOD, u >> 1) * (u & 1 ? v : 1) % MOD : 1;
}

int n, m, S[2];
vector<pii> adj[N];
ll dist[2][N], w[2][N];

inline void dijk(int id) {
  int so = S[id];
  memset(dist[id], 63, sizeof(dist[id]));
  dist[id][so] = 0;
  w[id][so] = 1;
  set<pair<ll, int>> st;
  st.insert({0, so});
  while (!st.empty()) {
    int v = st.begin()->second;
    st.erase(st.begin());
    for (auto e : adj[v]) {
      ll exp = dist[id][v] + e.second;
      if (exp < dist[id][e.first]) {
        st.erase({dist[id][e.first], e.first});
        dist[id][e.first] = exp;
        w[id][e.first] = w[id][v];
        st.insert({dist[id][e.first], e.first});
      } else if (exp == dist[id][e.first])
        add(w[id][e.first], w[id][v]);
    }
  }
}

int a[N], b[N], d[N];

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  read(n, m);
  readA(S, S + 2);
  rep(i, 0, m) {
    read(a[i], b[i], d[i]);
    adj[a[i]].pb({b[i], d[i]});
    adj[b[i]].pb({a[i], d[i]});
  }

  dijk(0);
  dijk(1);

  ll res = po(w[0][S[1]], 2);

  rep(i, 1,
      n + 1) if (dist[0][i] == dist[1][i] && dist[0][i] * 2 == dist[0][S[1]])
      add(res, -po(w[0][i] * w[1][i] % MOD, 2));
  rep(i, 0, m) {
    if (dist[0][a[i]] + d[i] == dist[0][b[i]] &&
        dist[0][b[i]] + dist[1][b[i]] == dist[0][S[1]] &&
        dist[0][b[i]] > dist[1][b[i]] && dist[1][a[i]] > dist[0][a[i]]) {
      add(res, -po(w[0][a[i]] * w[1][b[i]] % MOD, 2));
    }
    swap(a[i], b[i]);
    if (dist[0][a[i]] + d[i] == dist[0][b[i]] &&
        dist[0][b[i]] + dist[1][b[i]] == dist[0][S[1]] &&
        dist[0][b[i]] > dist[1][b[i]] && dist[1][a[i]] > dist[0][a[i]]) {
      add(res, -po(w[0][a[i]] * w[1][b[i]] % MOD, 2));
    }
  }

  write(res);

  return 0;
}
