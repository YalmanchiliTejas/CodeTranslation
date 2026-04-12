#include <iostream>
#include <string>
using namespace std;

int main(){

  string s;
  while(1){
  cin >> s;
  if(s == "#")break;
  int ans = 0;
  int now,cmp = -1;
  for(int i = 0;i < (int)s.size();i++){
    if(s[i] =='q'||s[i] =='w'||s[i] =='e'||s[i] =='r'||s[i] =='t'||s[i] =='a'||s[i] =='s'||s[i] =='d'||s[i] =='f'||s[i] =='g'||s[i] =='z'||s[i] =='x'||s[i] =='c'||s[i] =='v'||s[i] =='b' )now = 1;
    else now = 0;
    if(now != cmp)ans++;
    cmp = now;

}
  cout << ans - 1 << endl;
  }
  return 0;
}