#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>
using namespace std;

typedef string::const_iterator iter;
int factor(iter &p);
int number(iter &p);

int exprA(iter &p) {
  // cerr << "exprA" << endl;
  int res = number(p);
  while(true) {
    if(*p == '+') {
      ++p;
      res += number(p);
    }
    else if(*p == '*') {
      ++p;
      res *= number(p);
    }
    else break;
  }
  return res;
}

int exprB(iter &p) {
  // cerr << "exprB" << endl;
  int res = factor(p);
  while(true) {
    if(*p == '+') {
      ++p;
      res += factor(p);
    }
    else break;
  }
  return res;
}

int factor(iter &p) {
  // cerr << "factor" << endl;
  int res = number(p);
  while(true) {
    if(*p == '*') {
      ++p;
      res *= number(p);
    }
    else break;
  }
  return res;
}

int number(iter &p) {
  // cerr << "number" << endl;
  int res = 0;
  while(isdigit(*p)) {
    res *= 10;
    res += *p - '0';
    ++p;
  }
  return res;
}

int main() {
  string S; cin >> S;
  int T; cin >> T;
  iter p;
  p = S.begin();
	bool l2 = exprA(p)==T;
  p = S.begin();
	bool l1 = exprB(p)==T;
	if (l1 && l2) cout << "U" << endl;
	if (l1 && !l2) cout << "M" << endl;
	if (l2 && !l1) cout << "L" << endl;
	if (!l2 && !l1) cout<< "I" << endl;
}