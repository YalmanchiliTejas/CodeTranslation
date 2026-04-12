#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
  char in[3];
  for(int i=0; i<3;i++){
    cin >> in[i];
  }
  if(in[0]==in[1] && in[1]==in[2]){
    cout << "No";
  }else{
    cout << "Yes";
  }
}