#include<iostream>

using namespace std;
int main(){
  int x;
  cin >> x;
  if(x==3||x==5){
    cout << "YES\n";
  }
  else{
    if(x==7){
      cout << "YES\n";
    }
    else{
      cout << "NO\n";
    }
  }
  return 0;
}
