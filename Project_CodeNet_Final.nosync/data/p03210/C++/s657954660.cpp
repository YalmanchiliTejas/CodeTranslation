#include <iostream>

using namespace std;

int main(int argc, char** argv){
  int X;
  cin >> X;
  
  if( X == 3 || X == 5 || X == 7 ){
    cout << "YES" <<endl;
  }else{
    cout << "NO" << endl;
  }
  return 0;
}