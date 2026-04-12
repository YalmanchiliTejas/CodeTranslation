#include<iostream>
#include<string>

using namespace std;

bool isQwerty(char c){
  return !(
  c == 'y' ||
  c == 'u' ||
  c == 'i' ||
  c == 'o' ||
  c == 'p' ||
  c == 'h' ||
  c == 'j' ||
  c == 'k' ||
  c == 'l' ||
  c == 'n' ||
  c == 'm'
);
 return true;
}

int main(){

  while(true){

string str;
cin >> str;

if(str == "#")break;

int i = 0;
int ans = 0;

bool nowQwerty = isQwerty(str[i]);

for(i  = 1; i < str.size(); i++){
  if(nowQwerty != isQwerty(str[i])){
    ans++;
    nowQwerty = !nowQwerty;
  }
}

cout << ans << endl;
}

return 0;

}