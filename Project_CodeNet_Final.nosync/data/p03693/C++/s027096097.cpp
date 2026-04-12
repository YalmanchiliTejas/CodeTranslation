#include<iostream>
using namespace std;
int main(void){
  int a, b, c;
  cin >> a >> b >> c;
  (10*b + c) % 4 == 0 ? cout << "YES" << endl : cout << "NO" << endl;
  return 0;
}