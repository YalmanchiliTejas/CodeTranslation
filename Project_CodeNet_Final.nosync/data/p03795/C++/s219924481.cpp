#include<iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  if(n < 15) {
    cout << 800*n << endl;
  }else{
    cout << 800*n - (n/15)*200 << endl;
  }
  return 0;
}