#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <queue>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

#define fst first
#define snd second

typedef long long llint;
typedef pair<int, int> pii;

const int B = 27397, MOD = 1e9 + 7;
const int B1 = 33941, MOD1 = 1e9 + 9;

int n;
int min_cnt[26], curr_cnt[26];

int main(void) {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    memset(curr_cnt, 0, sizeof curr_cnt);

    for (char c : s)
      curr_cnt[c - 'a']++;

    for (int j = 0; j < 26; ++j)
      if (i == 0)
        min_cnt[j] = curr_cnt[j];
      else
        min_cnt[j] = min(min_cnt[j], curr_cnt[j]);
  }

  for (int i = 0; i < 26; ++i)
    for (int j = 0; j < min_cnt[i]; ++j)
      cout << (char) ('a' + i);

  cout << endl;

  return 0;
}