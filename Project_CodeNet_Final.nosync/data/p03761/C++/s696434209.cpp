/*  -*- coding: utf-8 -*-
 *
 * a.cc: C: 怪文書 / Dubious Document
 */

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<list>
#include<queue>
#include<deque>
#include<algorithm>
#include<numeric>
#include<utility>
#include<complex>
#include<functional>
 
using namespace std;

/* constant */

const int INF = 1 << 30;

/* typedef */

/* global variables */

int cs[26], mincs[26];

/* subroutines */

/* main */

int main() {
  for (int i = 0; i < 26; i++) mincs[i] = INF;

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    memset(cs, 0, sizeof(cs));
    for (int j = 0; j < s.size(); j++) cs[s[j] - 'a']++;
    for (int j = 0; j < 26; j++) mincs[j] = min(mincs[j], cs[j]);
  }

  for (int i = 0; i < 26; i++) {
    char c = 'a' + i;
    for (int j = 0; j < mincs[i]; j++) putchar(c);
  }
  putchar('\n');
  return 0;
}
