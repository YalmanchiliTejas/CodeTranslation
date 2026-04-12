#include <iostream>
#include <string>
using namespace std;

int main(){

  string r = "yuiophjklnm";
  string str;

  while(1){
    cin >> str;
    int flag = 1, ans = 0;
    if(str[0] == '#') break;
    char c = str[0];
    if(r.find(c) == string::npos) flag = 0;
    for(int i = 1; i < str.size(); i++){
      c = str[i];
      if(r.find(c) == string::npos){
        if(flag == 1){
          ans++;
          flag = 0;
        }
      }else{
        if(flag == 0){
          ans++;
          flag = 1;
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
