#include <bits/stdc++.h>
using namespace std;

int main(){
  int x,y,z;
  cin >> x >> y >> z;
  if((x-2*z)%(y+z)>=y){
    cout << (x-2*z)/(y+z)+1;
  }else{
    cout << (x-2*z)/(y+z);
  }
}