#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < (int) (n); i++)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

int main(){
  int n, a, b, c, x;
  while(cin >> n >> a >> b >> c >> x and n + a + b + c + x){
    int target[n];
    int got = 0;
    int res = -1;
    REP(i, n) cin >> target[i];
    REP(t, 10001){
      if(x == target[got]) got++;
      if(got==n) { res = t; break; }
      x=(a*x+b)%c;
    }
    cout << res << endl;
  }
}