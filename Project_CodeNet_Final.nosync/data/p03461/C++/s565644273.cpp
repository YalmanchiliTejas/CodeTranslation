#include <bits/stdc++.h>

#define pii pair<int, int>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define ll long long
#define ld long double
#define sz(v) int(v.size())
#define all(v) v.begin(), v.end()
#define vec vector<int>
#define dead not_bad
#define bad gooood

#define left not_right
#define y1 what

using namespace std;

const int N = (int) 150;
const int M = (int) 20;
const ll LINF = (ll) 1e18;
const int INF = (int) 1e9 + 7;
const int ALPHA = 26;
const int mod = INF + 2;
const double PI = 3.14159265359;
const ld EPS = (ld) 1e-12;

const int nx[4] = {0, 0, -1, 1};
const int ny[4] = {1, -1, 0, 0};

int A, B;
int d[N][N];
int f[N][N];

int main() {
  #define fn "saddle"
  #ifdef witch
      freopen("input.txt", "r", stdin);
  //    freopen("output.txt", "w", stdout);
  #else
      //freopen(fn".in", "r", stdin);
      //freopen(fn".out", "w", stdout);
  #endif
  cin >> A >> B;
  for (int i = 1; i <= A; i++) {
    for (int j = 1; j <= B; j++) {
      cin >> d[i][j];
    }
  }
  for (int a = 0; a < N; a++) {
    for (int b = 0; b < N; b++) {
      for (int i = 1; i <= A; i++) {
        for (int j = 1; j <= B; j++) {
          f[a][b] = max(f[a][b], d[i][j] - i * a - j * b);
        }
      }
    }
  }
  for (int i = 1; i <= A; i++) {
    for (int j = 1; j <= B; j++) {
      int mn = INF;
      for (int a = 0; a < N; a++) {
        for (int b = 0; b < N; b++) {
          mn = min(mn, f[a][b] + a * i + b * j);
        }
      }
      if (mn != d[i][j]) {
        cout << "Impossible";
        return 0;
      }
    }
  }
  cout << "Possible\n";
  cout << 200 << ' ' << 100 * 100 + 99 * 2 << endl;
  for (int a = 0; a + 1 < 100; a++) {
    cout << a + 1 << ' ' << a + 2 << " X\n";
  }
  for (int b = 0; b + 1 < 100; b++) {
    cout << 100 + b + 1 << ' ' << 100 + b + 2 << " Y\n";
  }
  for (int a = 0; a < 100; a++) {
    for (int b = 0; b < 100; b++) {
      cout << a + 1 << ' ' << 100 + 100 - b << ' ' << f[a][b] << "\n";
    }
  }
  cout << 1 << ' ' << 200;
  return 0;
}
