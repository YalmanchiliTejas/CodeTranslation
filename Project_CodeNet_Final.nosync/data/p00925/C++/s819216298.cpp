/*
 * b.cc: 
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

const int MAX_N = 100;

/* typedef */

/* global variables */

/* subroutines */

int num(string &s, int &pos) {
  return (s[pos++] - '0');
}

int term(string &s, int &pos) {
  int n0 = num(s, pos);
  while (pos < s.size() && s[pos] == '*') {
    pos++; // '*'
    int n1 = num(s, pos);
    n0 *= n1;
  }
  return n0;
}

int expr(string &s, int &pos) {
  int t0 = term(s, pos);
  while (pos < s.size() && s[pos] == '+') {
    pos++; // '+'
    int t1 = term(s, pos);
    t0 += t1;
  }
  return t0;
}

int ltor(string &s, int &pos) {
  int n0 = num(s, pos);
  while (pos < s.size()) {
    char op = s[pos++]; // '+' or '*'
    int n1 = num(s, pos);
    n0 = (op == '+') ? n0 + n1 : n0 * n1;
  }
  return n0;
}

/* main */

int main() {
  string s;
  int bans;
  cin >> s >> bans;

  int pos = 0;
  int e = expr(s, pos);

  pos = 0;
  int lr = ltor(s, pos);
  //printf("%d %d\n", e, lr);

  char ans = 'I';
  if (bans == e && bans != lr) ans = 'M';
  else if (bans != e && bans == lr) ans = 'L';
  else if (bans == e && bans == lr) ans = 'U';

  printf("%c\n", ans);
  return 0;
}