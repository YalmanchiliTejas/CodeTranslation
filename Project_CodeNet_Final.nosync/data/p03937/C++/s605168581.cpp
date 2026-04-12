#include <bits/stdc++.h>
using namespace std;

//--------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define RFOR(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define LL long long
#define INF INT_MAX/3

//--------------------------------------------
const double EPS = 1e-14;
const double PI  = acos(-1.0);

//--------------------------------------------

int main(){
  int h, w;
  string s;

  scanf("%d %d",&h, &w);

  int num = 0;
  REP(i, h) {
    cin >> s;
    while (s.size()) {
      int sh = s.find("#");
      if (sh != -1) {
        num++;
        s.erase(0, sh + 1);
      } else break;
    }
  }
  if (num == h + w - 1) printf("Possible\n");
  else printf("Impossible\n");

}
