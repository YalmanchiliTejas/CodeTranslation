#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <utility>
using namespace std;

#define rep(i,n) for(int (i)=0; (i)<(int)(n); ++(i))
#define foreach(c,i) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)

struct Team {
  string name;
  int pt, id;
  bool operator<(const Team& a) const {
    if (pt != a.pt) return pt > a.pt;
    return id < a.id;
  }
};

int n;
Team teams[12];

int main() {
  bool flag = false;
  while (cin >> n, n) {
    if (flag) {
      cout << endl;
    }
    int win, lose, draw;
    rep (i,n) {
      cin >> teams[i].name >> win >> lose >> draw;
      teams[i].id = i;
      teams[i].pt = win * 3 + draw;
    } 
    sort(teams, teams + n);
    rep (i,n) {
      cout << teams[i].name << "," << teams[i].pt << endl;
    }
    flag = true;
  }
  return 0;
}