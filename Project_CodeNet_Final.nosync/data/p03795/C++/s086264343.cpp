#include<iostream>
using namespace std;

int main(){
  int x,y,n;
  cin >> n;
  x = n*800;
  y = n/15;
  y *= 200;
  
  cout << x - y << endl;
  
  return 0;
}