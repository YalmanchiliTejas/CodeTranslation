#include<iostream>
#include<string>

using namespace std;
int main(){
  int x,y,z;
  cin >> x >> y >> z;
  x-=z;
  cout << x/(y+z) << "\n";
  return 0;
}
