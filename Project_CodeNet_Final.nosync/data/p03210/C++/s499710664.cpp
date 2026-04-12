#include <iostream>
#include <iomanip>
#include <string>

using namespace std;  //このネームスペースを使う

int main(){
  int X;

  cin >> X;

  if(X == 3 || X ==5 || X==7){
    cout << "YES" << endl; 
  }
  else{
    cout << "NO" << endl;
  }
  return 0;
}
