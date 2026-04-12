#include <bits/stdc++.h>
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
typedef long long ll;
const int MOD = 1000000007;
const int INF = 1010000000;
const double EPS = 1e-10;
using namespace std;

int main() {
  int a,b,c,x,y,ans,lim;
  cin >> a >> b >> c >> x >> y;
  ans = a*x+b*y;
  lim = max(x,y);
  repd(i,1,lim+1){
    int amai = (x-i>=0)?x-i:0;
    int bmai = (y-i>=0)?y-i:0;
    int cans = a*amai+b*bmai+c*2*i;
    ans = min(ans,a*amai+b*bmai+c*2*i);
  }
  cout << ans << endl;
}
