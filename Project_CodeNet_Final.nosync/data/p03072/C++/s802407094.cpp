#include <bits/stdc++.h>
using namespace std;

#define REP(i, a, n) for(int i=a; i<n; i++) //(i, 0, n)でi=0~n-1までn回
#define REPn(i, a, n) for(int i=a; i<=n; i++) //(i, 1, n)でi=1~nまでn回
#define sorts(v) sort(v.begin(), v.end());
#define sortg(v) sort(v.begin(), v.end(), greater<>());
#define rev(v) reverse(v.begin(), v.end()); //逆順に並べ替え

int main() {
  int n, cnt=1, h=0;
  cin >> n;
  vector<int> v(n);
  REP(i, 0, n) cin >> v.at(i);
  REP(i, 0, n-1){
    h = max(h, v[i]);
    if(h<=v.at(i+1))cnt++;
  }
  cout << cnt << endl;
}