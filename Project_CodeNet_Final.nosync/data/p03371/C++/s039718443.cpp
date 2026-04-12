#include<iostream>
using namespace std;

int main(){
  int A,B,C,X,Y;  cin >> A >> B >> C >> X >> Y;
  long long min = 1LL << 60;
  for(int c=0;;c = c + 2){
    int a = X - c/2;
    int b = Y - c/2;
    if(a < 0 && b < 0)  break;
    if(a < 0) a = 0;
    if(b < 0) b = 0;
    if(min > a*A + b*B + c*C){
      min = a*A + b*B + c*C;
    }
  }
  cout << min << endl;
}
