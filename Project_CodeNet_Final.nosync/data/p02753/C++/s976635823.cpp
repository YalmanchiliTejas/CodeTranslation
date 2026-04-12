#include <iostream>
#include <string>
#define rep(i, n) for(unsigned int i = 0; i < (unsigned int)(n); i++)
using namespace std;

int main(){
  string str;
  cin >> str;
  int count = 0;

  rep(i, str.size()){
    if(str[i] == 'A'){
      count++;
    }
  }

  if(count == 0 || count == 3){
    cout << "No" << endl;
  }else{
    cout << "Yes" << endl;
  }
}