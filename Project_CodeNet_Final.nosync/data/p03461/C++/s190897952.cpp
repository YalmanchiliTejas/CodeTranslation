#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

constexpr int DEBUG = 0;

template<typename T>
vector<vector<T>> Make2DVector(int d1, int d2, T default_value) {
  return vector<vector<T>>(d1, vector<T>(d2, default_value));
}

template<class T> inline bool UpdateMin(T& a, T b) {
  if (a > b) { a = b; return 1; } return 0;
}

template<class T> inline bool UpdateMax(T& a, T b) {
  if (a < b) { a = b; return 1; } return 0;
}

constexpr int D_MAX = 100;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int x_max;
  int y_max;
  cin >> x_max >> y_max;

  auto d_matrix = Make2DVector(x_max + 1, y_max + 1, 0);
  for (int x = 1; x <= x_max; x++) {
    for (int y = 1; y <= y_max; y++) {
      cin >> d_matrix[x][y];
    }
  }

  auto c_matrix = Make2DVector(D_MAX + 1, D_MAX + 1, 0);
  for (int a = 0; a <= D_MAX; a++) {
    for (int b = 0; b <= D_MAX; b++) {
      for (int x = 1; x <= x_max; x++) {
        for (int y = 1; y <= y_max; y++) {
          UpdateMax(c_matrix[a][b], d_matrix[x][y] - a * x - b * y);
        }
      }
    }
  }

  auto check_fn = [&]() -> bool {
    for (int x = 1; x <= x_max; x++) {
      for (int y = 1; y <= y_max; y++) {
        int d = INT32_MAX;
        for (int a = 0; a <= D_MAX; a++) {
          for (int b = 0; b <= D_MAX; b++) {
            UpdateMin(d, a * x + b * y + c_matrix[a][b]);
          }
        }
        // cout << d << endl;
        if (d > d_matrix[x][y]) return false;
      }
    }
    return true;
  };

  if (!check_fn()) {
    cout << "Impossible" << endl;
    return 0;
  }

  cout << "Possible" << endl;
  cout << 2 * D_MAX + 2 << " " << D_MAX + D_MAX + (D_MAX + 1) * (D_MAX + 1) << endl;
  for (int i = 0; i + 1 <= D_MAX; i++) {
    cout << 1 + i << " " << 1 + i + 1 << " " << "X" << endl;
  }
  for (int i = 0; i + 1 <= D_MAX; i++) {
    cout << D_MAX + 1 + 1 + i << " " << D_MAX + 1 + 1 + i + 1 << " " << "Y" << endl;
  }
  for (int a = 0; a <= D_MAX; a++) {
    for(int b = 0; b <= D_MAX; b++) {
      cout << 1 + a << " " << 2 * D_MAX + 2 - b << " " << c_matrix[a][b] << endl;
    }
  }
  cout << 1 << " " << 2 * D_MAX + 2 << endl;
}