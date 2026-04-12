/**
 *    author:  tourist
 *    created: 16.11.2019 23:39:30       
**/
#include <bits/stdc++.h>

using namespace std;

template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}

template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  int minn = (int) 1e9 + 1;
  int maxx = 0;
  int min2 = (int) 1e9 + 1;
  int max2 = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    if (a[i] > b[i]) swap(a[i], b[i]);
    minn = min(minn, a[i]);
    maxx = max(maxx, b[i]);
    min2 = min(min2, b[i]);
    max2 = max(max2, a[i]);
  }
  long long ans = (long long) (maxx - min2) * (long long) (max2 - minn);
  vector<pair<int, int>> c(n);
  for (int i = 0; i < n; i++) {
    c[i] = make_pair(a[i], b[i]);
  }
  sort(c.begin(), c.end());
  multiset<int> s;
  for (int i = 0; i < n; i++) {
    s.insert(c[i].first);
  }
  for (int i = 0; i <= n; i++) {
    int x = *s.begin();
    int y = *s.rbegin();
    ans = min(ans, (long long) (y - x) * (maxx - minn));
    if (i < n) {
      s.erase(s.find(c[i].first));
      s.insert(c[i].second);
    }
  }
  cout << ans << '\n';
  return 0;
}
