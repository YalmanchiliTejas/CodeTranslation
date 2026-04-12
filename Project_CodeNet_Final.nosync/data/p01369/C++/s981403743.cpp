#include<iostream>
using namespace std;
string str;
typedef unsigned us;
char r[] = "yuiophjklnm";
bool isRight(char c){
  for(us i = 0;i < sizeof(r);i++){
    if(c == r[i])return true;
  }
  return false;
}
int solve(const string &str){
  int res = 0;
  bool isr = false;
  isr = isRight(str[0]);
  for(unsigned i = 0;i < str.size();i++){
    if(isr != isRight(str[i])){
      res += 1;
      isr = isRight(str[i]);
    }
  }
  return res;
}

int main(){
  while(true){
    getline(cin,str);
    if(str == "#")break;
    cout << solve(str) << endl;
  }
  return 0;
}