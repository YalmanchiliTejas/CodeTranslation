#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <complex>
#include <cstring>
#include <cstdlib>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()

struct hoge {
  int s, n;
  string name;
  hoge(int s,int n, string name) : s(s),n(n),name(name) { }
};
bool operator < (const hoge &a, const hoge &b) {
  return a.s!=b.s ? a.s>b.s : a.n < b.n;
}

int main() {
  int n;
  int f = 0;
  while(cin>>n,n) {
    vector<hoge> v;
    REP(i,n) {
      string name;
      int a,b,c;
      cin >> name;
      cin >> a >> b >> c;
      v.push_back(hoge(a*3+c,i,name));
    }
    sort(ALL(v));
    if (f)
      cout << endl;
    else
      f++;
    FOR(it,v) {
      hoge h=*it;
      cout << h.name << "," << h.s << endl;
    }
  }
}