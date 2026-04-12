#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll MOD=1000000007;

int main() {
  int r,g,b;
  cin >> r >> g >> b;
  if((10*g+b)%4==0){
    cout << "YES" << endl;
  }
  else
    cout << "NO" << endl;
}