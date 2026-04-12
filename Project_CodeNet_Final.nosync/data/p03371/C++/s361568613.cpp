#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);
static const int INF = 1e9+7;



int main(){
  int A, B, C, x, y;
  cin >> A >> B >> C >> x >> y;

  ll mincost = 1e12;


  REP2(c,0,200010){
    int a, b;
    ll cost = 0;
    a = 0; b = 0;
    a = max(0, x - c/2);
    b = max(0, y - c/2);

    cost = a*A + b*B + c*C;
    mincost = min(cost, mincost);
  }

  cout << mincost << endl;

  return 0;
}
