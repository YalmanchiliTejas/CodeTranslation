#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

typedef long long LL;
typedef vector<LL> VL;
typedef vector<vector<LL>> VVL;
typedef vector<vector<char>> VVC;
typedef vector<string> VS;
typedef vector<pair<LL, LL>> VP;

#define REPD(i,a,b) for (LL i=(a);i<(b);i++)
#define REP(i,n) REPD(i,0,n)

LL llRead(){
  LL a;
  cin >> a;
  return a;
};

string stringRead(){
  string a;
  cin >> a;
  return a;
};

vector<LL> vlRead(LL a){
  vector<LL> rv;
  REP(i, a){
    LL input;
    cin >> input;
    rv.push_back(input);
  }
  return rv;
}

vector<string> vsRead(LL a){
  vector<string> rv;
  REP(i, a){
    string input;
    cin >> input;
    rv.push_back(input);
  }
  return rv;
}

VP vpRead(LL n) {
  VP rv;
  REP(i, n) {
    auto a = llRead();
    auto b = llRead();
    rv.push_back(make_pair(a,b));
  }
  return rv;
}

VVL vvlRead(LL a, LL b){
  vector<vector<LL>> rv;
  REP(i, a){
    rv.push_back(vector<LL>());
    REP(j, b) {
      LL input;
      cin >> input;
      rv.at(i).push_back(input);
    }
  }
  return rv;
}

VVC vvcRead(LL a, LL b){
  VVC rv;
  REP(i, a){
    rv.push_back(vector<char>());
    REP(j, b) {
      char input;
      cin >> input;
      rv.at(i).push_back(input);
    }
  }
  return rv;
}

#if 1
#define DEBUG_VECTOR_NEWLINE

#define debug(d) debug1(__LINE__,#d, d)
void debug1(LL line, const char* name, VL& v) {
  cout << line << ":" << name << ":vector<LL>(" << v.size() << ") ";
  REP(i, (LL)v.size()) {
    cout << v.at(i) << " ";
  }
  cout << endl;
}
void debug1(LL line, const char* name, double i) {
  cout << line << ":" << name << ":double " << i << endl;;
}
void debug1(LL line, const char* name, LL i) {
  cout << line << ":" << name << ":LL " << i << endl;;
}
void debug1(LL line, const char* name, VS& v) {
  cout << line << ":" << name << ":vector<string>(" << v.size() << ") ";
  REP(i, (LL)v.size()) {
    cout << v.at(i) << " ";
  }
  cout << endl;
}
void debug1(LL line, const char* name, VVL& v) {
  cout << line << ":" << name << ":vector<vector<LL>>(" << v.size() << ") ";
#ifdef DEBUG_VECTOR_NEWLINE
  cout << endl;
#endif
  REP(i, (LL)v.size()) {
    REP(j, (LL)v.at(i).size()) {
      cout << v.at(i).at(j) << " ";
    }
    cout << ", ";
#ifdef DEBUG_VECTOR_NEWLINE
    cout << endl;
#endif
  }
  cout << endl;
}
void debug1(LL line, const char* name, VVC& v) {
  cout << line << ":" << name << ":vector<vector<char>>(" << v.size() << ") ";
#ifdef DEBUG_VECTOR_NEWLINE
  cout << endl;
#endif
  REP(i, (LL)v.size()) {
    REP(j, (LL)v.at(i).size()) {
      cout << v.at(i).at(j) << " ";
    }
    cout << ", ";
#ifdef DEBUG_VECTOR_NEWLINE
    cout << endl;
#endif
  }
  cout << endl;
}
void debug1(LL line, const char* name, char* s) {
  cout << line << ":" << name << ":char* " << s << endl;;
}
void debug1(LL line, const char* name, char c) {
  cout << line << ":" << name << ":char " << c << endl;;
}
void debug1(LL line, const char* name, string& s) {
  cout << line << ":" << name << ":string " << s << endl;;
}
void debug1(LL line, const char* name, vector<const char*>& v) {
  cout << line << ":" << name << ":vector<const char*>(" << v.size() << ") ";
  REP(i, (LL)v.size()) {
    cout << v.at(i) << " ";
  }
  cout << endl;
}
void debug1(LL line, const char* name, priority_queue<LL>& p) {
  cout << line << ":" << name << ":priority_queue<LL>(" << p.size() << ") ";
  priority_queue<LL> copy = p;
  while(!copy.empty()) {
    cout << copy.top() << " ";
    copy.pop();
  }
  cout << endl;
}
void debug1(LL line, const char* name, vector<pair<LL,LL>>& v) {
  cout << line << ":" << name << ":vector<pair<LL,LL>>(" << v.size() << ") ";
  REP(i, (LL)v.size()) {
    cout << v.at(i).first << "," << v.at(i).second << " ";
  }
  cout << endl;
}
void debug1(LL line, const char* name, map<LL,LL>& m) {
  cout << line << ":" << name << ":map<LL,LL>(" << m.size() << ") ";
  for (auto p : m) {
    cout << p.first << "," << p.second << " ";
  }
  cout << endl;
}
void debug1(LL line, const char* name, multimap<LL,LL>& m) {
  cout << line << ":" << name << ":map<LL,LL>(" << m.size() << ") ";
  for (auto p : m) {
    cout << p.first << "," << p.second << " ";
  }
  cout << endl;
}
#else
#define debug(n)
#endif

#define BASE (1000000007)

LL factm(LL n) {
  debug(n);
  LL ret = 1;
  REPD(i,2,n+1) {
    ret*=i;
    ret=ret%BASE;
  }
  debug(ret);
  return ret;
}

LL inv(LL a) {
    LL b = BASE, u = 1, v = 0;
    while (b) {
        LL t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= BASE;
    if (u < 0) u += BASE;
    return u;
}
int main(int argc, const char * argv[]) {
	cout.precision(16);
  // source code

  auto N = llRead();
  auto M = llRead();

  if (N == M) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
