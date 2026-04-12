#include<iostream>
using namespace std;

int main(){
  int x,y,z;
  cin >> x >> y >> z;
  int out = 0;
  x-=z;
  while(x>=0){
    x-=(y+z);
    out++;
  }
  out--;
  cout << out << endl;

  return 0;
}