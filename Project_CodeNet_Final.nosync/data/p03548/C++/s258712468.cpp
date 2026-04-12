#include <bits/stdc++.h>
using namespace std;

int main() {
  int X,Y,Z;
  cin >> X >> Y >> Z;
  
  int N = 0;
  while(1){
    if((Y * N + Z * (N + 1)) > X){
    	break;
    }
    N++;
  }

  cout << N - 1 << endl; 
  return 0;
}
