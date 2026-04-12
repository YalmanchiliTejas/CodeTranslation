#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main(){
  int r, g, b;
  cin >> r >> g >> b;

  if ((100*r + 10* g + b) % 4 == 0){
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
