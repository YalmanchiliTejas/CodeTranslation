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
#include <cctype>
using namespace std;

#define rep(i,n) for(int (i)=0; (i)<(int)(n); ++(i))
#define foreach(c,i) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)

int N, M;
char buf[1024];
const char blah[][10] = {
  "Fizz____",
  "Buzz____",
  "FizzBuzz",
};

int main() {
  while (scanf("%d%d",&M,&N),N|M) {
    //fill(flag, flag + M, true);
    queue<int> q;
    rep(i,M) q.push(i+1);
    //int curNum = 1;
    rep(i,N) {
      scanf("%s",buf);
      if (q.size() == 1) continue;
      int cur = q.front(); q.pop();
      int n = strlen(buf);
      bool ok = true;
      int check = 0;
      check |= (i+1)%3 ? 0 : 1 ;
      check |= (i+1)%5 ? 0 : 2 ;
      if (check) {
        if (check == 1) {
          rep(j,4) if (blah[0][j] != buf[j]) ok = false;
          if (n != 4) ok = false;
        } else if (check == 2) {
          rep(j,4) if (blah[1][j] != buf[j]) ok = false;
          if (n != 4) ok = false;
        } else {
          rep(j,8) if (blah[2][j] != buf[j]) ok = false;
          if (n != 8) ok = false;
        }
      } else {
        if (i+1 != atoi(buf)) ok = false;
        rep(j,n) if (!isdigit(buf[j])) ok = false;
      }
      if (ok) q.push(cur);
      //else printf("%s:%d is out.\n",buf,cur);
    }
    vector<int> v;
    while (!q.empty()) { v.push_back(q.front()); q.pop(); }
    sort(v.begin(), v.end());
    rep(i,v.size()) {if(i)putchar(' ');printf("%d",v[i]);} puts("");
  }
  return 0;
}