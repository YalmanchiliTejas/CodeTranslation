#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int r, g, b;
  cin >> r >> g >> b;

  int num = 100 * r + 10 * g + b;
  if (num % 4 == 0){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }

}
