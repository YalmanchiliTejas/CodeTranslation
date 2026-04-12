#include<iostream>
using namespace std;

int main(int argc, char *argv[])
{
  int A,B,C,X,Y;
  cin >> A >> B >> C >> X >> Y;
  long sum = 0;
  if((A+B) > 2 * C){ // ABピザを買った方がAとBをばらばらに買うより安い場合．
    int n = max(X,Y) - abs(X - Y);
    X -= n;
    Y -= n;
    sum += 2 * n * C;
  }
  if(A > 2*C){ //Aピザを買うより，ABピザからAピザだけを作った方が安い場合
    sum += 2*C*X;
  }else{
    sum += A*X;
  }

  if(B > 2*C){// Bピザを買うより，ABピザからBピザだけを作った方が安い場合．
    sum += 2*C*Y;
  }else{
    sum += B*Y;
  }
  cout << sum << endl;
  return 0;
}
