#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;
typedef long long ll;
typedef vector<int> vi;

int H;
int W;
int f[1000][1000];
vector<int> ordR;
vector<int> ordC;

bool solveRow() {
  vi prev;
  prev.push_back(0);
  for (int i = 1; i < H; ++i) {
    bool okPrev = true;
    int pi = ordR[prev.back()];
    int ci = ordR[i];
    for (int j = 0; j < W; ++j) {
      if (f[ci][j] > f[pi][j]) {
	okPrev = false;
	break;
      }
    }
    if (okPrev) {
      prev.push_back(i);
      continue;
    }
    bool ok = false;
    for (int j = prev.size() - 2; j >= 0; --j) {
      int pastI = ordR[prev[j]];
      ok = true;
      for (int k = 0; k < W; ++k) {
	if (f[ci][k] > f[pastI][k]) {
	  ok = false;
	  break;
	}
      }
      if (ok) {
	break;
      }
    }
    if (!ok) {
      return false;
    }
    prev.clear();
    prev.push_back(i - 1);
    prev.push_back(i);
  }
  return true;
}

bool solveCol() {
  vi prev;
  prev.push_back(0);
  for (int i = 1; i < W; ++i) {
    bool okPrev = true;
    int pi = ordC[prev.back()];
    int ci = ordC[i];
    for (int j = 0; j < H; ++j) {
      if (f[j][ci] > f[j][pi]) {
	okPrev = false;
	break;
      }
    }
    if (okPrev) {
      prev.push_back(i);
      continue;
    }
    bool ok = false;
    for (int j = prev.size() - 2; j >= 0; --j) {
      int pastI = ordC[prev[j]];
      ok = true;
      for (int k = 0; k < H; ++k) {
	if (f[k][ci] > f[k][pastI]) {
	  ok = false;
	  break;
	}
      }
      if (ok) {
	break;
      }
    }
    if (!ok) {
      return false;
    }
    prev.clear();
    prev.push_back(i - 1);
    prev.push_back(i);
  }
  return true;
}

int main() {
  scanf("%d %d", &H, &W);
  int mr = 0;
  int mc = 0;
  int max = 0;
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      scanf("%d", &f[i][j]);
      if (max < f[i][j]) {
	max = f[i][j];
	mr = i;
	mc = j;
      }
    }
  }
  {
    vector<ll>r(H);
    for (int i = 0; i < H; ++i) {
      r[i] = ((ll) f[i][mc] << 10) + i;
    }
    sort(r.begin(), r.end());
    ordR.resize(H);
    for (int i = 0; i < H; ++i) {
      ordR[i] = (int) (r[H - 1 - i] & ((1 << 10) - 1));
    }
  }
  {
    vector<ll> c(W);
    for (int i = 0; i < W; ++i) {
      c[i] = ((ll) f[mr][i] << 10) + i;
    }
    sort(c.begin(), c.end());
    ordC.resize(W);
    for (int i = 0; i < W; ++i) {
      ordC[i] = (int) (c[W - 1 - i] & ((1 << 10) - 1));
    }
  }
  printf(solveRow() && solveCol() ? "YES\n" : "NO\n");
  return 0;
}