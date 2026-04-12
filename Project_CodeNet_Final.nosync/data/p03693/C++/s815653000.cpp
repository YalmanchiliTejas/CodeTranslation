#include<iostream>
using namespace std;
int main(){
  int a,b;
  cin >> a >> a >> b;
  b += a * 10;
  cout << (b%4==0? "YES":"NO") << endl;
}
