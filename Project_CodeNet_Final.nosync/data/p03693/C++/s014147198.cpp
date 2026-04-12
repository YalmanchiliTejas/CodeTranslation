#include<iostream>
using namespace std;

int main(void){
  int r,g,b;
  cin >> r >> g >> b;
  int number = r*100 + g*10 + b;
  if(number%4 == 0){
    cout << "YES" << '\n';
  }
  else{
    cout << "NO" << '\n';
  }
}
