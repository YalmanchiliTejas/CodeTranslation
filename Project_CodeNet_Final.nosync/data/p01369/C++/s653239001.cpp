#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(){
  string str;
  int count=0;
  int flag=0;
  int tokusyu = 0;
  string migi = "zaqxswcdevfrbgt";
  string hida = "nhymjukiolp";

  while(cin >> str){
    if(str[0] == '#'){
      break;
    }
    count = 0;
    flag = 0;
    tokusyu = 0;

    for(int i = 0;i < str.length();i++){
      for(int j = 0;j < migi.length();j++){
        if(migi[j] == str[i] && flag == 1){
          count += 1;
          flag = 0;
        }
        if(str[i] == migi[j]){
          tokusyu = 1;
        }
      }
      for(int j = 0;j < hida.length(); j++){
        if(count == 0 && tokusyu == 0){
          flag = 1;
        }

        if(hida[j] == str[i] && flag == 0){
          count += 1;
          flag = 1;
        }
      }
    }
    cout << count << endl;
  }
}