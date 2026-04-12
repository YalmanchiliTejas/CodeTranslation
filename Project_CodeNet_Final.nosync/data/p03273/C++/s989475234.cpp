#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define INF (long long)(1e9+7)
#define REP(i,n) for(ll i = 0; i < n; i++)
#define REP1(i,n) for(ll i = 1; i <= n; i++)

string a[110];
int hc[110]={0};
int wc[110]={0};

int main(void)
{
  int h,w;
  cin >> h >> w;
  REP(i, h) {
    cin >> a[i];
  }
  REP(i, h) {
    REP(j, w) {
      if(a[i][j]=='.') {
	hc[i] ++;
	wc[j] ++;
      }
    }
  }
  /*
  REP(i, h) printf("%d ", hc[i]);
  printf("\n");
  REP(j, w) printf("%d ", wc[j]);
  printf("\n");
  */

  
  REP(i, h) {
    if(hc[i] != w) {
      //  printf("%3d %3d ", hc[i], h);
      REP(j, w) {
	if(wc[j] != h) {
	  printf("%c", a[i][j]);
	}
      }
      printf("\n");
    }
  }
  
  
}
