#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair< ll, ll > pll;
typedef pair< int, int > pii;

const double pi = 3.14159265358979323846;

// #define fio() cin.tie(0); ios::sync_with_stdio(false);
// template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
// template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }
#define MOD 1000000007LL
#define PS(p) cout << setprecision(15) << fixed << p << endl;
#define UNIQUE(v) v.erase(std::unique(v.begin(), v.end()), v.end());
#define ALL(c) c.begin(), c.end()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define MT make_tuple
#define TG0 get< 0 >
#define TG1 get< 1 >
#define TG2 get< 2 >
#define F first
#define S second
#define VL vector< ll >

// to_string(123)
// atoi("123"); atoi(s.c_str());
// "abc".size()
// s.find('+') == string::npos
// 1e18

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  string S;
  cin >> S;

  bool isA = false;
  bool isB = false;
  for (auto c : S) {
    if (c == 'A') {
      isA = true;
    }
    if (c == 'B') {
      isB = true;
    }
  }

  if (isA && isB) {
    cout << "Yes" << endl;

  } else {
    cout << "No" << endl;
  }

  return 0;
}
