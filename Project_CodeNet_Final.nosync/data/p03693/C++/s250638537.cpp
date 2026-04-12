#include<bits/stdc++.h>

using namespace std;

int main(void){
  int r, g, b;
  cin >> r >> g >> b;
  
  int ans = r*100 + g*10 + b;
  
  cout << (ans % 4 == 0 ? "YES" : "NO") << endl;
}