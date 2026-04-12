#include<iostream>
#include<algorithm>
using namespace std;

int main(int argc,char** argv){
  int A,B,C,X,Y;
  int num_a=0;
  int num_b=0;
  int num_c=0;
  cin >> A >> B >> C >> X >> Y;
  if(C*2 < A + B){
    num_c = 2 * min(X,Y);
    if(X>Y){
      if(A < C * 2){
        num_a = X-Y;
      }else{
        num_c += 2 * (X - Y);
      }
    }
    if(Y>X){
      if(B < C * 2){
	num_b = Y-X;
      }else{
	num_c += 2 * (Y - X);
      }
    }
  }else{
    num_a = X;
    num_b = Y;
  }
  cout << num_a * A + num_b * B + num_c * C << endl;
  return 0;
}
