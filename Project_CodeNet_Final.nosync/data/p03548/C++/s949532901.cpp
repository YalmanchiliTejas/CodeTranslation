#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int X, Y, Z, i;
    cin >> X >> Y >> Z;
    for (i = 1; i < 100000; i++){
      if (X < Y * i + Z * (i + 1)){
        cout << (i - 1)<< endl;
        break;
      }
    }
}