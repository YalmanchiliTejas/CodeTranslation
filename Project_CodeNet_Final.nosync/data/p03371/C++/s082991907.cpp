#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#define rep(i,w) for (int i = 0;i < (w); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int INF = 1e9;


int main(){
  int a,b,c,x,y;cin >> a >> b >> c >> x >> y;
  int ans = INF;
  int temp = a*x + b*y;
  ans = temp;
  while(x > 0 || y > 0){
    if(x > 0) temp -= a;
    if(y > 0) temp -= b;
    temp += 2*c;
    x = max(x-1,0);
    y = max(y-1,0);
    ans = min(ans,temp);
  }
  cout << ans << endl;
}