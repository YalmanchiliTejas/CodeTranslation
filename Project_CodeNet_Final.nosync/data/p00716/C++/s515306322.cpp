#include <bits/stdc++.h>
using namespace std;

int main(){

  int m;

  cin >> m;

  while(m--){
    int M, n, y;
    cin >> M >> y >> n;

    long long ans = -1;
    int judge = 0;
    double a, b, c, d;

    for(int i = 0; i < n; i++){
      long long cp = M;
      long long bb = 0;
      cin >> a >> b >> c;
      for(int j = 0; j < y; j++){
        if(a == 1){
          cp = b*cp + cp - c;
          // cout << ans << endl;
        }else {
          bb += cp*b;
          cp -=  c;
          judge = 1;
        }
      }
      // cout << cp << " "  << bb << endl;
      if(judge == 1) cp = cp + bb;
      judge = 0;
      ans = max(ans,cp);
    }
    cout << ans << endl;
  }


}