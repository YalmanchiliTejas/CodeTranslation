#include <bits/stdc++.h>

#define REP(i,n) for(int i=0;i<(int)(n);i++)

using namespace std;

pair<int,int> factor(string s, int i) {
  int num = s[i] - '0';
  while(++i < s.size() && s[i] == '*') {
    num *= s[++i] - '0';
  }
  return make_pair(num, i);
}

int expr(string s) {
  int num, i;
  tie(num, i) = factor(s, 0);
  while(i < s.size()) {
    int p, j;
    tie(p, j) = factor(s, i+1);
    num += p;
    i = j;
  }
  return num;
}

int expr2(string s) {
  int i = 0;
  int num = s[i] - '0';
  while(++i < s.size()) {
    if (s[i] == '*')
      num *= s[++i] - '0';
    else
      num += s[++i] - '0';
  }
  return num;
}

int main() {
  string s;
  cin>>s;
  int ans;
  cin>>ans;
  int bob = expr2(s);
  int calc = expr(s);
  if (ans == bob) {
    if (ans == calc) {
      cout << 'U' << endl;
    } else {
      cout << 'L' << endl;
    }
  } else {
    if (ans == calc) {
      cout << 'M' << endl;
    } else {
      cout << 'I' << endl;
    }
  }
  return 0;
}