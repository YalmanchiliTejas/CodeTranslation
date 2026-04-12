#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  int r, g, b;
  cin >> r >> g >> b;

  if ((100 * r + 10 * g + b) % 4 == 0){
    cout << "YES" << endl;
  }
  else
  {
    cout << "NO" << endl;
  }
  
}