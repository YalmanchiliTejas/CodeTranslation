#include <bits/stdc++.h>
using namespace std;

int main() {
 int X,Y,Z;
 cin >> X >> Y >> Z;
  int l = Z;
  int c = 0;
  for(int i = 0; i<100009;i++){
    if(i%2 == 0){
     l += Y;
     c++;
    }
    else l += Z;
    if(X-l < Y+Z){
      break;
    }
  }
  cout << c << endl;

}
