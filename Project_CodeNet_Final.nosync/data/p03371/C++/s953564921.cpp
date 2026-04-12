#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define r(i,n) for(int i=0;i<n;i++)
using namespace std;

int main(){
  int A,B,C,X,Y;
  cin >> A >> B >> C >> X >> Y;
  int ans=0;
  int min=X>Y?Y:X;
  if(A+B>C*2){
    ans += C * min*2;

    if(X>Y){
      if(A>C*2){
        ans += C*(X-Y)*2;
      }else{
        ans += A*(X-Y);
      }
    }else{
      if(B>C*2){
        ans += C*(Y-X)*2;
      }else{
        ans += B*(Y-X);
      }
    }

  }else{
    ans += A*X + B*Y;
  }
  
  cout << ans << endl;
  return 0;
}