#include <iostream>
#include <complex>
#include <sstream>
#include <string>
#include <algorithm>
#include <deque>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <vector>
#include <set>
#include <limits>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;
#define REP(i, j) for(int i = 0; i < (int)(j); ++i)
#define FOR(i, j, k) for(int i = (int)(j); i < (int)(k); ++i)
#define SORT(v) sort((v).begin(), (v).end())
#define REVERSE(v) reverse((v).begin(), (v).end())
typedef pair<int, char *> P;

P fact(char *p);
P term(char *p);
P expr(char *p);

P fact(char *p){
  if(isdigit(*p)){
    int t = *(p++) - '0';
    while(isdigit(*p)) t = t * 10 + *(p++) - '0';
    return P(t, p);
  } else if(*p == '('){
    P r = expr(p + 1);
    if(*r.second != ')') exit(0); //閉じ括弧が無いエラー
    return P(r.first, r.second + 1);
  } else{
    exit(0); //括弧でも数字でもないエラー
  }
}

P term(char *p){
  P r = fact(p);
  while(*r.second == '*' || *r.second == '/'){
    char op = *r.second;
    int tmp = r.first;
    r = fact(r.second + 1);
    if(op == '*') r.first *= tmp;
    else r.first /= tmp;
  }
  return r;
}

P expr(char *p){
  P r = term(p);
  while(*r.second == '+' || *r.second == '-'){
    char op = *r.second;
    int tmp = r.first;
    r = term(r.second + 1);
    if(op == '+') r.first = tmp + r.first;
    else r.first = tmp - r.first;
  }
  return r;
}

int num(string s, int &p){
  int res = 0;
  while(p < (int)(s.length()) && isdigit(s[p])){
    res *= 10;
    res += s[p++] - '0';
  }
  return res;
}

int calc(string s){
  int p = 0, res = num(s, p);
  while(p < s.length()){
    char c = s[p++];
    int n = num(s, p);
    if(c == '+') res += n;
    else res *= n;
  }
  return res;
}

int main() {
  string s; cin >>s;
  int res; cin >>res;
  char *cs = new char[(int)(s.length()) + 1];
  strcpy(cs, s.c_str());
  P tmp = expr(cs);
  int n = calc(s);
  if(tmp.first == res && n != res) cout <<"M" <<endl;
  else if(tmp.first != res && n == res) cout <<"L" <<endl;
  else if(tmp.first == res && n == res) cout <<"U" <<endl;
  else cout <<"I" <<endl;
  return 0;
}