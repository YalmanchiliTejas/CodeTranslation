#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define INF 1000000000000000000

int main(){
  int H, W;
  cin >> H >> W;
  int count = 0;
  bool judge = 0;
  rep(i, H){
    rep(j, W){
      char a;
      cin >> a;
      if (a == '#') count++;
    }
  }
  
  if (count == H + W - 1) judge = 1;
  if (judge) cout << "Possible" << endl;
  else cout << "Impossible" << endl;
  
  
    
}