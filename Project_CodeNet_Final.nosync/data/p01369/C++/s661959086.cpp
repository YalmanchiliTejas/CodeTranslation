#include <iostream>
using namespace std;

int main(void){
  string s, left;
  int pos, tmp, cnt, i;
  left = "qwertasdfgzxcvb";
  while(1){
    cin >> s;
    if(s == "#"){
      break;
    }
    if(left.find(s[0]) != std::string::npos){
      pos = 0;
    }else{
      pos = 1;
    }
    cnt = 0;
    for(i=1;i<s.length();i++){
      if(left.find(s[i]) != std::string::npos){
        tmp = 0;
      }else{
        tmp = 1;
      }
      if(pos != tmp){
        cnt++;
        pos = tmp;
      }
    }
    cout << cnt << endl;
  }
  return 0;
}

