#include <bits/stdc++.h>

using namespace std;

typedef long long lli;
typedef vector<lli> vll;
typedef vector<bool> vbl;
typedef vector<vector<lli>> mat;

lli n;
mat xy,yx;
lli max_elm = 0;
lli min_elm = LONG_MAX;
lli min_range = LONG_MAX;

int main(){
  cin >> n;
  xy = mat(n,vll(2));
  yx = mat(n,vll(2));
  for(lli i = 0;i < n;i++) cin >> xy[i][0] >> xy[i][1];
  for(lli i = 0;i < n;i++) if(xy[i][0] > xy[i][1]) swap(xy[i][0],xy[i][1]);
  for(lli i = 0;i < n;i++) yx[i][0] = xy[i][1],yx[i][1] = xy[i][0];
  sort(xy.begin(),xy.end());
  sort(yx.begin(),yx.end());
  min_elm = min(xy[0][1],yx[n-1][1]);
  max_elm = max(xy[0][1],yx[n-1][1]);
  for(lli i = 1;i < n;i++){
    min_range = min(min_range,max(xy[n-1][0],max_elm)-min(xy[i][0],min_elm));
    max_elm = max(max_elm,xy[i][1]);
    min_elm = min(min_elm,xy[i][1]);
  }

  cout << min(min_range*(yx[n-1][0]-xy[0][0]),(xy[n-1][0]-xy[0][0])*(yx[n-1][0]-yx[0][0])) << endl;


  return 0;
}
