#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <complex>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <climits>
#include <queue>
#include <set>
#include <map>
#include <valarray>
#include <bitset>
#include <stack>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1<<29;
const double PI = acos(-1);
const double EPS = 1e-8;

string card[4][13];
int main() {
  string hoge = "23456789TJQKA";
  map<char, int> ten;
  REP(i,13)ten[hoge[i]]=i;
  char trump;
  while(cin>>trump, trump!='#') {
    REP(i,4) REP(j,13)
      cin >> card[i][j];
    int ew = 0, ns = 0;
    int win = 0;
    REP(i,13) {
      int ma = -1;
      int led = card[win][i][1];
      REP(j,4) {
        int score = ten[card[j][i][0]];
        if (card[j][i][1]==trump) score += 100;
        if (card[j][i][1]==led) score += 50;
        if (score > ma) {
          ma = score;
          win = j;
        }
      }
      // cout << ma << " " << win << endl;
      if (win==0||win==2) ns++;
      else ew++;
    }
    if (ew > ns) cout << "EW" << " " << ew-6 << endl;
    else cout << "NS" << " " << ns-6 << endl;
  }
}