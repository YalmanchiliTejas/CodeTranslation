#include<iostream>
#include<string>
using namespace std;
int main(){
  int a = 0, b = 0;
  for(int i = 0; i < 3; i++){
    char c;
    cin >> c;
    if(c == 'A'){
      a++;
    }
    else{
      b++;
    }
  }
  if(a == 3 || b == 3){
    cout << "No";
  }
  else{
    cout << "Yes";
  }
}
      
