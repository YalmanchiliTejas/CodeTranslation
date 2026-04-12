#include <bits/stdc++.h>

using namespace std;

template <class T> void mini(T &l, T r) {l = min(l, r);}
template <class T> void maxi(T &l, T r) {l = max(l, r);}

string to_string(string s) {
  return '"' + s + '"';
}

string to_string(bool a) {
  return a ? "T" : "F";
}
 
string to_string(const char* s) {
  return to_string((string) s);
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
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

using ll = long long;
using ld = long double;

const int N = 101;

int A, B;
int d[N][N];
int a[N][N];

void run() {
  cin >> A >> B;
  for (int i = 1; i <= A; ++i) {
    for (int j = 1; j <= B; ++j) {
      cin >> d[i][j];
    }
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      for (int x = 1; x <= A; ++x) {
        for (int y = 1; y <= B; ++y) {
          maxi(a[i][j], d[x][y] - i * x - j * y);
        }
      }
    }
  }
  for (int x = 1; x <= A; ++x) {
    for (int y = 1; y <= B; ++y) {
      bool ok = 0;
      for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
          if (a[i][j] + i * x + y * j == d[x][y]) {
            ok = 1;
          }
        }
      }
      if (!ok) {
        puts("Impossible");
        return;
      }
    }
  }

  puts("Possible");
  printf("%d %d\n", 2 * N, N * N + (N - 1) * 2);
  for (int i = 0; i + 1 < N; ++i) {
    printf("%d %d X\n", i + 1, i + 2);
    printf("%d %d Y\n", N + i + 2, 1 + N + i);
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      printf("%d %d %d\n", i + 1, j + N + 1, a[i][j]);
    }
  }
  printf("1 %d\n", N + 1);
}

int main() {
  run();
  return 0;
}
