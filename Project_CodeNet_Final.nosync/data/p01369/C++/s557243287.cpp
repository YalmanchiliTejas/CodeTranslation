#include <bits/stdc++.h>
using namespace std;
#define LEFTHAND  0;
#define RIGHTHAND 1;

string s;
string leftkey  = "qwertasdfgzxcvb";

int leftOrRight(int index){
  for(int i=0; i < leftkey.size(); i++){
    if(leftkey[i] == s[index]) return LEFTHAND;
  }
  return RIGHTHAND;
}

int main(void){
  while(cin >> s, s[0] != '#'){
    int change = 0;
    int previous = leftOrRight(0);
    for(int i=1; i < s.length(); i++){
      int now = leftOrRight(i);
      if(previous == now){
      }else{
	change++;
      }
      previous = now;
    }
    cout << change << endl;
  }
  return 0;
}