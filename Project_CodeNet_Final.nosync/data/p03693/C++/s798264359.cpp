#include<bits/stdc++.h>
using namespace std;

int main(){
  int r, g, d; cin >> r >> g >> d;
  int a = r * 100 + g * 10 + d;
  if(a % 4 == 0) cout << "YES" << endl;
  else cout << "NO" << endl;
}  
