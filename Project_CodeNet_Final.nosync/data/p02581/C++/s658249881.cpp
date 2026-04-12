
#include <iostream>

using namespace std;

const int kMaxN = 2002;

int a[kMaxN * 3];
int f[kMaxN * 3][kMaxN * 3], p[kMaxN][kMaxN];
int n, ans;

void T0(int i, int j, int g) {  // 用g组的卡替换i
  g *= 3;
  f[j][g] = max(f[j][g], f[i][j] + (a[i] == a[g + 1] && a[i] == a[g + 2]));
  f[j][g + 1] = max(f[j][g + 1], f[i][j] + (a[i] == a[g] && a[i] == a[g + 2]));
  f[j][g + 2] = max(f[j][g + 2], f[i][j] + (a[i] == a[g] && a[i] == a[g + 1]));
}

void T1(int i, int j, int g) {  // 用g组的牌替换j
  g *= 3;
  f[i][g] = max(f[i][g], f[i][j] + (a[j] == a[g + 1] && a[j] == a[g + 2]));
  f[i][g + 1] = max(f[i][g + 1], f[i][j] + (a[j] == a[g] && a[j] == a[g + 2]));
  f[i][g + 2] = max(f[i][g + 2], f[i][j] + (a[j] == a[g] && a[j] == a[g + 1]));
}

void T2(int i, int j, int g) {  // 用g组的牌替换i和j
  g *= 3;
  f[g][g + 1] = max(f[g][g + 1], f[i][j] + (a[i] == a[j] && a[i] == a[g + 2]));
  f[g][g + 2] = max(f[g][g + 2], f[i][j] + (a[i] == a[j] && a[i] == a[g + 1]));
  f[g + 1][g + 2] = max(f[g + 1][g + 2], f[i][j] + (a[i] == a[j] && a[i] == a[g]));
}

void P() {  // 预处理
  int m = 2;
  for (int i = 3; i < 3 * n; i += 3) {           // 枚举组
    if (a[i] == a[i + 1] && a[i] == a[i + 2]) {  // 有一组相同直接消除
      ans++;
    } else {
      a[++m] = a[i], a[++m] = a[i + 1], a[++m] = a[i + 2];
    }
  }
  a[++m] = a[3 * n];  // 最后一组
  n = m / 3;
  for (int i = n; i >= 1; i--) {  // 预处理每组之后每种数字第一次出现的组
    for (int j = 1; j <= n; j++) {
      p[i][j] = p[i + 1][j];
    }
    p[i][a[i * 3]] = p[i][a[i * 3 + 1]] = p[i][a[i * 3 + 2]] = i;
  }
}

int main() {
  cin >> n;
  for (int i = 1; i <= 3 * n; i++) {
    cin >> a[i];
  }
  P();
  for (int j = 1; j < 3 * n; j++) {
    for (int i = 1; i < j; i++) {
      int g = j / 3 + 1;
      T0(i, j, g);
      T1(i, j, g);
      T2(i, j, g);
      if (p[g + 1][a[i]]) {
        T0(i, j, p[g][a[i]]);
        T2(i, j, p[g][a[i]]);
      }
      if (p[g + 1][a[j]]) {
        T1(i, j, p[g][a[j]]);
        T2(i, j, p[g][a[j]]);
      }
    }
  }
  cout << ans + f[3 * n + 1][3 * n + 2];
  return 0;
}