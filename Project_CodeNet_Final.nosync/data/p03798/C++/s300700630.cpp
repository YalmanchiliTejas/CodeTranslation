#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define reps(i, n) for (int i = 1; i <= (n); i++)
#define all(a) (a).begin(), (a).end()
#define bit(b) (1ull << (b))

using namespace std;
using i32 = int;
using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;
using f64 = double;
using vi32 = vector<i32>;
using vu32 = vector<u32>;
using vi64 = vector<i64>;
using vu64 = vector<u64>;
using vf64 = vector<f64>;
using vstr = vector<string>;
using vvi32 = vector<vi32>;
using vvu32 = vector<vu32>;
using vvi64 = vector<vi64>;
using vvu64 = vector<vu64>;
using vvf64 = vector<vf64>;

template<typename T, typename S> bool amax(T &x, S y) { if (x < y) { x = y; return 1; } return 0; }
template<typename T, typename S> bool amin(T &x, S y) { if (y < x) { x = y; return 1; } return 0; }

int N;
string S;

void display(vi32 &b) {
  rep(i, b.size()) cout << (b[i] ? 'W' : 'S');
  cout << endl;
}

bool check(vi32 &b, int i) {
  int p = i - 1, n = i + 1;
  if (p < 0) p += N;
  if (n >= N) n -= N;
  if (S[i] == 'o') {
    if (b[i] == 0 && b[p] == b[n]) {
      return true;
    } else if (b[i] == 1 && b[p] != b[n]){
      return true;
    }
  } else {
    if (b[i] == 0 && b[p] != b[n]) {
      return true;
    } else if (b[i] == 1 && b[p] == b[n]){
      return true;
    }
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(16);
  cin >> N;
  cin >> S;
  vvi32 p = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
  rep(i, 4) {
    vi32 b(N);
    b[0] = p[i][0];
    b[1] = p[i][1];
    for (int j = 2; j < N; j++) {
      if (S[j - 1] == 'o') {
        if (b[j - 1] == 0) {
          b[j] = b[j - 2];
        } else {
          b[j] = 1 - b[j - 2];
        }
      } else {
        if (b[j - 1] == 0) {
          b[j] = 1 - b[j - 2];
        } else {
          b[j] = b[j - 2];
        }
      }
    }
    // rep(i, N) cout << b[i];
    // cout << endl;
    if (check(b, N - 1) && check(b, 0)) {
      display(b);
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}