#include<bits/stdc++.h> 
using namespace std;
using ll = long long;
using ull = unsigned long long;


int main(){
  int r,g,b;
  cin >> r >> g >> b;
  int n = 100*r + 10*g + b;
  if( n%4 == 0 ){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
  return 0;
}
