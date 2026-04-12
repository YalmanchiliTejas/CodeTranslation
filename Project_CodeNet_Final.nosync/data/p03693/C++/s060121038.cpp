#include<iostream>
using namespace std;

int main(){
  int a, b, c;
  cin >> a >> b >> c;
  
  int n = a * 100 + b * 10 + c;
  if(n % 4 == 0){
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  
  return 0;
}
