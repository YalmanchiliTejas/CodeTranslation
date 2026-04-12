
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)

using namespace std;

int vs[30];

int main(void) {
  int n;
  cin >> n;
  int res = 0;
  REP(i, n) {
    cin >> vs[i];
    bool isOK = true;
    REP(j, i) {
      if(vs[j] > vs[i]) {
        isOK = false;
        break;
      }
    }
    if(isOK) {
      ++res;
    }
  }
  cout << res << endl;
  
  return 0;
}
