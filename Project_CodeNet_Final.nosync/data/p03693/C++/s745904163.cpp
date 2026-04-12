#include <bits/stdc++.h>
using namespace std;

int main(){
 int r,g,b;
  cin >> r >> g >> b;
  //４の倍数は下二桁が4の倍数だったらおｋっていうやつ
  int res = g * 10 + b;
  if(res % 4 == 0){
   cout << "YES" << endl; 
  }else{
   cout << "NO" << endl; 
  }
}