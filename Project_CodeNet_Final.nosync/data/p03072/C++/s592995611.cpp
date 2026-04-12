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
  int n;
  cin >> n;
  vector<int> h(n);
  REP(i,n) cin >> h[i];
  int maxh = h[0];
  int cnt = 0;
  REP(i,n){
    if(h[i] >= maxh){
      maxh = h[i];
      cnt++;
    }

  }

  cout << cnt << endl;
  return 0;
}
