#include<iostream> //cinなど
#include<string> //文字列
#include<algorithm> //sort など
#include<math.h> //paw(冪乗など)
#include<set> // 集合
#include<map> //写像
#include<stdio.h> //printf
#include<stack>

using namespace std;
int main(){
  int r,g,b,sum;
  cin>> r >> g >> b;
  sum = r*100 + g*10 + b;
  if(sum % 4 == 0){
    cout<< "YES" <<endl;
  }else{
    cout<< "NO" <<endl;
  }
  return 0;
}
