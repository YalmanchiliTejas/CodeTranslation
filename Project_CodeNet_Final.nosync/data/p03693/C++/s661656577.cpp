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
  int r, g, b;
  cin >> r >> g >> b;
  int ans = r * 100 + g * 10 + b;
  if(ans%4 == 0) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}
