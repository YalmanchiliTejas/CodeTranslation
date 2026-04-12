#include<iostream>
using namespace std;

int main(){
  int x,y,z;
  cin >> x >> y >> z;
  int count = 0;
  while(x > 0){
    if(count == 0){
      x -= y+2*z;
      count++;
    }
    x -= y+z;
    if(x >= 0){
      count++;
    }
  }
  cout << count << endl;
}
