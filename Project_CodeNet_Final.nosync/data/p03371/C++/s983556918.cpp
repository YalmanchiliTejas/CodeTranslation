#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
const int inf = 1001001001;

int main(){
  int a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;

  
  int ans = a*x+b*y;
  rep(i,200001){
    int tot = i*c;
    int n = i/2;
    if(x-n>0) tot += a*(x-n);
    if(y-n>0) tot += b*(y-n);
    ans = min(ans,tot);
  }
  cout << ans << endl;
}
