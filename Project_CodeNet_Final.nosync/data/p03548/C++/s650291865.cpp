#include<iostream>
using namespace std;

int main(){
  int x, y, z;
  cin >> x >> y >> z;
  
  int n = x - z;
  cout << n / (y + z) << endl;
}