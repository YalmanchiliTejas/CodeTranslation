#include <bits/stdc++.h>
using namespace std;
int main() {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  if ( (A+B) < 2*C ){
    cout << A*X + B*Y << endl;			//ABせっと０
  } else if ( A > 2*C && X >= Y ){
    cout << 2*C*X << endl;				//全部ABせっと
  } else if ( B > 2*C && X < Y ){
    cout << 2*C*Y << endl;				//全部ABせっと
  } else if ( X > Y && (A+B) > 2*C ){
    cout << 2*C*Y + A*(X-Y) << endl;	//ABせっと + Aかいたす
  } else{
    cout << 2*C*X + B*(Y-X) << endl;	//ABせっと + Bかいたす
  }
}

