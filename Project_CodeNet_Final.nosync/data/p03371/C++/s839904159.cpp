#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
  int A,B,C,X,Y;
  int max;
  int loop;
  int min;
  int minx;

  cin >> A >> B >> C >> X >> Y;
  int AB = A*X + B*Y;
  min = AB;

  
  if(X>Y){
    loop = X;
  }else{
    loop = Y;
  }

  int res = AB;
  for(int i=1;i<loop+1;i++){
    res = res + C*2;
    if(i<=X){
      res= res -A;
    }
    if(i<=Y){
      res= res -B;
    }
    if(min>res){
      min=res;
      minx=i;
    }
  } 
  
  cout << min << endl;
  
  return 0;
}