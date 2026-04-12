#include <iostream>
using namespace std;

int main() {
  int a ;
  cin >> a ;
  
  if(a >= -40 && a <30){
    cout << "No" << endl;
  } 
 else if (a >=30 && a <= 40){
    cout << "Yes" << endl;
 }
}