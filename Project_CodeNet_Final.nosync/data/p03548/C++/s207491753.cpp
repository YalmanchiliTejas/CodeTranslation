#include<bits/stdc++.h>
using namespace std;

int main(){
  int X, Y, Z;
  cin >> X >> Y >> Z;
  int ans = 0;
  int j = 0;
  
  for(int i=1; i<X; i++){
    ans = i*Y + (i+1)*Z;
    j++;
    if(ans > X){
      break;
    }
  }
  
  cout << j - 1 << endl;
  
}