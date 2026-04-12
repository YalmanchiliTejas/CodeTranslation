#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int, int> P;//d, v
const int max_n = 5000+10;
const int INF = 1e6;
struct edge{
  int from,to,cost;
};
bool comp(const edge& e1, const edge& e2){
  return e1.cost < e2.cost;
}
ll a,b,c,x,y;
vector<edge> G[max_n];
int dist[max_n];
int dist2[max_n];
edge es[max_n];
ll dp[max_n][max_n];
int main(){
  cin >> a>>b>>c>>x>>y;
  ll atob = a + b;
  ll ans = 0;
  ll mi = min(x,y);
  if(atob < 2*c){
      ans += a*x + b*y;
  }else{
    ans += mi*2*c;
    x -= mi;  y -= mi;
    ans += min(x*a+y*b, 2*c*max(x,y));
  }
  cout << ans << endl;
  return 0;
}
