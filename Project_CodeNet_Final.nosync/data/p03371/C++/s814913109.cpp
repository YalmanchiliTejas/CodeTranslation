#include <bits/stdc++.h>
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define sqrep(i,cc,n) for(long long i=cc;i*i<=n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>
 
using ll = long long;

const vector<int> dx = {1, 0, -1, 0};
const vector<int> dy = {0, 1, 0, -1};
const ll inf = 1001001001;
const ll e9  = 1000000000;
const ll mod = 1000000007;

int main(){
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  if(y>=x){
    int ans = min({a*x+b*y,2*c*x+b*(y-x),2*c*max(x,y)});
    cout << ans << endl;
    return 0;
  }else{
    int ans = min({a*x+b*y,2*c*y+a*(x-y),2*c*max(x,y)});
    cout << ans << endl;
    return 0;
  }
}