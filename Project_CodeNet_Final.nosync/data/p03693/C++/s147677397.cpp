#include <iostream>
using namespace std;

int main(){
  int R, G, B;
  cin >> R >> G >> B;
  if((G*10 + B)%4==0){
    cout<<"YES";
  }
  else{
    cout<<"NO";
  }
  return 0;
}
