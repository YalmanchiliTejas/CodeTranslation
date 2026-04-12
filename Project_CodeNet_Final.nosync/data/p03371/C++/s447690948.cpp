#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int A,B,C,X,Y;
  cin >> A >> B >> C >> X >> Y;
  
  if (A+B <= C*2) {
    //AとBを買ったほうが安い場合
    //cout << "A:";
    cout << A*X + B*Y << endl;
  }
  else {
    //Cを買ったほうが安い場合
    int total = 0;
    if (X>=Y) total = min(X,Y)*2*C + (X-Y)*A;
    else total = min(X,Y)*2*C + (Y-X)*B;
    //cout << "B:";
    cout << min(total,max(X,Y)*2*C) << endl;
  }
  return 0;
}