#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
const int inf = 1001001001;
int main(){
  int a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;
  int ans = inf;
  rep(i,max(x,y)+1){
    int nc = 2*i;
    int na = max(0,x-i);
    int nb = max(0,y-i);
    ans = min(ans,nc*c+na*a+nb*b);
  }
  cout << ans << endl;
  return 0;
}
