#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <string>
#include <map>

using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
static const double EPS = 1e-9;
static const double PI = acos(-1.0);

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, n) for (int i = (s); i < (int)(n); i++)
#define FOREQ(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define FORIT(it, c) for (__typeof((c).begin())it = (c).begin(); it != (c).end(); it++)
#define MEMSET(v, h) memset((v), h, sizeof(v))

struct Character {
  string name;
  int v;
  int index;
  Character() {;}
  Character(string name, int v, int index) : name(name), v(v), index(index) {;}
  bool operator<(const Character &rhs) const {
    if (v != rhs.v) { return v > rhs.v; }
    return name < rhs.name;
  }
};

Character character[100010];
Character sorted[100010];
int fav[100010];
bool bfav[100010];
int need[100010];
bool used[100010];
int n, m, k, l;

bool calc(int t) {
  if (t > k || t > m) { return false; }
  MEMSET(used, false);
  REP(i, k - t + 1) {
    if (bfav[sorted[i].index]) {
      used[sorted[i].index] = true;
      t--;
    }
    if (t <= 0) { return true; }
  }
  Character target = sorted[k - t];
  REP(i, m) {
    int index = fav[i];
    if (used[index]) {
      need[i] = l + 1;
      continue;
    }
    need[i] = max(0, target.v - character[index].v);
    if (target.name < character[index].name) {
      need[i]++;
    }
  }
  sort(need, need + m);
  ll sum = 0;
  REP(i, t) {
    sum += need[i];
  }
  return sum <= l;
}

char str[1000];
int main() {
  while (scanf("%d %d %d %d", &n, &m, &k, &l), n|m|k|l) {
    MEMSET(bfav, false);
    map<string, int> mapto;
    REP(i, n) {
      int v;
      scanf("%s %d", str, &v);
      character[i] = Character(str, v, i);
      sorted[i] = character[i];
      mapto[str] = i;
    }
    sort(sorted, sorted + n);
    REP(i, m) {
      scanf("%s", str);
      fav[i] = mapto[str];
      bfav[fav[i]] = true;
    }
    sort(fav, fav + m);
    int left = 0;
    int right = min(m, k) + 1;
    while (left != right) {
      int mid = (left + right) / 2;
      if (calc(mid)) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    left--;
    printf("%d\n", left);
  }
}