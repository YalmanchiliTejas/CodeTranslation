#include <iostream>
using namespace std;
int main(void){
  int n;
  cin >> n;
  
  if(n == 3||n == 5||n == 7)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  
  return 0;
}