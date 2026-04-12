#include<bits/stdc++.h>
using namespace std;
int main(void){

  int A , B , C , X , Y;  cin >> A >> B >> C >> X >> Y;
  int C2 = C * 2; //Cを二枚買うときの値段
  int ans = 0;

  if(A + B <= C2){
    ans = A * X + B * Y;
  }else{
    int i = 0;  //iはC2を買う枚数
    while(i < X && i < Y){
      i++;
      ans += C2;
    }
    //今AかBを買う必要のある枚数が片っぽ0の状況
    if(X - i != 0 && C2 < A){
      ans += C2 * (X - i);
    }else if(Y - i != 0 && C2 < B){
      ans += C2 * (Y - i);
    }else{
      ans += A * (X - i) + B * (Y - i);
    }
  }

  printf("%d\n", ans);
return 0;
}