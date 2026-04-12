#include <bits/stdc++.h>
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
typedef long long ll;
using namespace std;
const int MOD = 1000000007;
const int INF = 1010000000;
const double EPS = 1e-10;
const array<pair<int,int>,4> fd{make_pair(1,0),make_pair(-1,0),make_pair(0,1),make_pair(0,-1)}; 

int main(){
  int a,b,c,x,y;cin>>a>>b>>c>>x>>y;
  int ans = a*x + b*y;
  repd(i,1,max(x,y)+1){
    int aa = ans - a - b + 2*c;
    if(i > x)aa += a;
    if(i > y)aa += b;
    ans = min(ans, aa);
  }
  cout << ans << endl;
}
