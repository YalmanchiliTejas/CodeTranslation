#include<iostream>
using namespace std;

int main(){
  char s[3];
  bool judge = 0;
 
  for(int i = 0;i < 3;i++){
    cin >> s[i];
  }
  for(int i = 0;i < 2;i++){
    if(s[i] != s[i + 1]){
      judge = 1;
    }
  }
  if(judge){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }

  return 0;
}
