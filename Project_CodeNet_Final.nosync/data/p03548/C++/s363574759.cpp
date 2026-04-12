#include <bits/stdc++.h>
using namespace std;

int main(){
  int X,Y,Z,max_A=0;
  cin >> X >> Y >> Z;
  for(int i=0;;i++){
    long long A=(i+1)*Y+(i+2)*Z;
    if(A>X){
      break;
    }
    max_A=i+1;
  }
  cout << max_A << endl;
}   