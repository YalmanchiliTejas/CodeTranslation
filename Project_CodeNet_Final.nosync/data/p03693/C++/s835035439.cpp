#include <iostream>
using namespace std;

int main(){
  int R, G, B;
  cin >> R >> G >> B;
  int num = R * 100 + G * 10 + B;
  if(num % 4 == 0){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
}