#include <iostream> //cin,cout
#include <fstream> //input.txtの入力
#include <vector> //vector
using namespace std;

int main(){
  //ifstream in("input.txt");
  //cin.rdbuf(in.rdbuf());

  int A,B,C,X,Y;
  cin>>A>>B>>C>>X>>Y;

  int betsu,wake;

  betsu = A*X+B*Y;
  
  if(X>Y){
    wake = min( Y*C*2 + (X-Y)*A, X*C*2 );
  }
  else if(Y>X){
    wake = min( X*C*2 + (Y-X)*B, Y*C*2 );
  }
  else{
    wake = Y*C*2;
  }

  //cout<<betsu<<' '<<wake<<endl;

  cout<<min(betsu,wake)<<endl;

}