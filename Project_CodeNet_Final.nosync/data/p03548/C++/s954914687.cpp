#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  int X, Y, Z;
  cin >> X >> Y >> Z;

  int people = 0;
  X -= Z;
  while(X > 0){
    X -= (Y + Z);
    if (X >= 0){
      people += 1;  
    }
    
  }

  cout << people << endl;
}