#include<bits/stdc++.h>
using namespace std;

int main(){
  int r,g,b,A,B;
  cin >> r >> g >> b;
  A=10*g+b;
  B=A%4;
  if(B==0){
    cout << "YES" <<endl;
  }
  else{
    cout << "NO" <<endl;
  }
}
    