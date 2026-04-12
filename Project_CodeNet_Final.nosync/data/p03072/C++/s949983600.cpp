#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);



int main(){
  int n;
  cin >> n;
  vector<int> h(n);
  REP(i,n) cin >> h[i];

  int ans  = 0;
  int MX = 0;
  REP(i,n){
    if(h[i] >= MX) ++ans;
    MX = max(h[i], MX);
  }

  cout << ans << endl;


  return 0;
}