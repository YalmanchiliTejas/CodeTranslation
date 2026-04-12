#include<iostream>
using namespace std ;

int main(){
  int r,g,b,num;
  cin >> r ;
  cin >> g ;
  cin >> b ;
  
  num = 10*g + b ;
  if(num%4==0){
    cout << "YES" << endl ;
  }else{
  	cout << "NO" << endl ;
  }
  return 0 ;
}