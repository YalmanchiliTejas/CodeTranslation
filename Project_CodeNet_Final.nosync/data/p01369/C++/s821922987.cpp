#include<bits/stdc++.h>
using namespace std;

string r = "yuiophjklnm";
string l = "qwertasdfgzxcvb";

bool hand(char c){
  for(int i = 0; i < r.length(); i++){
    if(c == r[i])return true;
  }
  return false;
}

int main(){
  string str;
  while(cin >> str, str != "#"){
    bool now = hand(str[0]);//r = true, l = false;

    int cnt = 0;
    for(int i = 1; i < str.length(); i++){
      if(now != hand(str[i])){
        cnt++;
        now = !now;
      }
    }
    cout << cnt << endl;
  }
}