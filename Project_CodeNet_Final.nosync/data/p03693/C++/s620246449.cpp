#include <iostream>
#include <string>
#include <string.h>
using namespace std;
int main(){
  int f1,f2,f3,sub;
  cin >> f1 >> f2 >> f3;
  sub = f1 * 100 + f2 * 10 + f3;
  if(sub%4 == 0){
    cout << "YES";
  }else{
    cout << "NO";
  }
}