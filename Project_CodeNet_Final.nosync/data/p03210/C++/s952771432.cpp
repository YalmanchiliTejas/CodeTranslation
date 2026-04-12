#include <iostream>
#include <string>
using namespace std;

int main(){
  int X;
  string celebrate;
  cin >>X;
  if(X==3 || X==5 || X==7){
    celebrate = "YES";
  }
  else{
    celebrate = "NO";
  }
  cout << celebrate;
}
    
    