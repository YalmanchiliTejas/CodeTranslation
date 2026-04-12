#include<bits/stdc++.h>
using namespace std;

int main(){
  int r, g, b;
  cin >> r >> g >> b;
  int sum=0;
  sum = 100*r+10*g+b;
  bool ans = sum%4==0;
  if (ans){
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
  }
}