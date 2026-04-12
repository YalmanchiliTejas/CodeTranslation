#include <bits/stdc++.h>
using namespace std;

int main(){
  int A,B,C,X,Y;
  cin >> A >> B >> C >> X >> Y;
  int yen = -1;
  if(A+B >= C*2){
    int cn = min(X,Y);
    for(int a = 0; a <= X-cn; a++){
      for(int b = 0; b <= Y-cn; b++){
        int c = max(X-cn-a,Y-cn-b)*2;
        int cost = A*a+B*b+C*(c+cn*2);
        if(yen == -1 || yen > cost){
          yen = cost;
        }
      }
    }
  }else{
    int cn = min(X,Y);
    for(int a = cn; a <= X; a++){
      for(int b = cn; b <= Y; b++){
        int c = max(X-a,Y-b)*2;
        int cost = A*a+B*b+C*c;
        if(yen == -1 || yen > cost){
          yen = cost;
        }
      }
    }
  }
  cout << yen << endl;
}