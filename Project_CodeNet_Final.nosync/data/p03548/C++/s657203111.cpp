#include<iostream>
using namespace std;

int main(){
  int x, y, z;
  cin >> x >> y >> z;

  for(int i = 0; ; i++){
    if((z*(i+1) + y*i) > x){
      cout << i-1 << endl;
      break;
    }
  }

  return 0;

}