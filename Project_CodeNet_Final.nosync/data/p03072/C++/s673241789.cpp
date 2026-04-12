#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define MAX(a, b, c) max(max(a, b), c)
using namespace std;

int main(){
  int n;
  scanf("%d", &n);
  int h[n];
  REP(i,n) scanf("%d", &h[i]);
  int ans = 1;
  int max_h = h[0];
  FOR(i,1,n){
    if(h[i] >= max_h){
      ans++;
      max_h = h[i];
    }
  }
  cout << ans << endl;
}