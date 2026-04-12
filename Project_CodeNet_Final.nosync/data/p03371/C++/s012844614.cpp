#include <iostream>
using namespace std;
int main(){
  int A,B,C,X,Y,fee=1<<30;
  cin >> A >> B >> C >> X >> Y;
  //ABピザ2i枚買う場合
  for(int i=0;i<=max(X,Y);i++){
      fee = min(fee,A*max(0,X-i)+B*max(0,Y-i)+C*2*i);
  }
  cout << fee << endl;
  return 0;
}