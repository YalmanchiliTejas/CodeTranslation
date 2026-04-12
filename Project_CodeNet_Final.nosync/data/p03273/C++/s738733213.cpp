#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
using namespace std;
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
typedef long long ll;
#define INF (1<<29)

int main(){
  int H, W;
  string a[200];
  int x[200], y[200];
  cin >> H >> W;
  for(int i=0;i<H;i++)cin >> a[i];
  for(int i=0;i<H;i++){
    bool f=true;
    for(int j=0;j<W;j++)if(a[i][j]=='#')f=false;
    if(f)x[i]=1;
    else x[i]=0;
  }
  for(int i=0;i<W;i++){
    bool f=true;
    for(int j=0;j<H;j++)if(a[j][i]=='#')f=false;
    if(f)y[i]=1;
    else y[i]=0;
  }
  for(int i=0;i<H;i++){
    if(x[i]==1)continue;
    for(int j=0;j<W;j++){
      if(y[j]==0)cout << a[i][j];
    }
    puts("");
  }

  return 0;
}
