
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)

using namespace std;

typedef long long ll;

char buf[100000+10];
char res[100000+10];

int main(void) {
  ll n;
  cin >> n >> buf;

  REP(pat, 4) {
    memset(res, 0, sizeof res);
    res[n-1] = (pat & 1) ? 'S' : 'W';
    res[n-2] = (pat & 2) ? 'S' : 'W';
    bool ok = true;
    REP(i, n) {
      int count = 0;
      count += res[(i-1+n)%n] == 'S';
      count += res[(i-2+n)%n] == 'S';
      char tobe = !!(count % 2) == !!(buf[(i-1+n)%n] == 'o') ? 'W' : 'S';
      if(res[i] && res[i] != tobe) {
        ok = false;
      } else {
        res[i] = tobe;
      }
    }
    if(ok) {
      puts(res);
      return 0;
    }
  }
  puts("-1");
  
  return 0;
}
