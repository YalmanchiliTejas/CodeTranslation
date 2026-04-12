#include<iostream>
using namespace std;

int main(){
  int n, x, y;
  cin >> n;
  for(int i=1; n >= i; i++){
    if(i == 0){
      x += 800;
    }else if((i % 15) == 0){
      x += 600;
    }else{
      x += 800;
    }
  }
  //int result = x - y;
  cout << x << endl;
  return 0;
}