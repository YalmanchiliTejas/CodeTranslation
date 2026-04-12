#include<bits/stdc++.h>
using namespace std;

int main(void){
  int n, flg=0;
  string s, ss, str[4]={"SS","SW","WS","WW"};
  cin >> n >> s;
  for(int i=0;i<4;++i){
    ss = str[i];
    for(int j=1;j<s.size()-1;++j){
      if(ss[j]=='S'){
        if(ss[j-1]=='S'){
          if(s[j]=='o'){
            ss += 'S';
          }else{
            ss += 'W';
          }
        }else{
          if(s[j]=='o'){
            ss += 'W';
          }else{
            ss += 'S';
          }
        }
      }else{
        if(ss[j-1]=='S'){
          if(s[j]=='o'){
            ss += 'W';
          }else{
            ss += 'S';
          }
        }else{
          if(s[j]=='o'){
            ss += 'S';
          }else{
            ss += 'W';
          }
        }
      }
    }
    if(ss[n-1]=='S'){
      if(ss[0]==ss[n-2]){
        if(s[n-1]=='x'){
          continue;
        }
      }else{
        if(s[n-1]=='o'){
          continue;
        }
      }
    }else{
      if(ss[0]==ss[n-2]){
        if(s[n-1]=='o'){
          continue;
        }
      }else{
        if(s[n-1]=='x'){
          continue;
        }
      }
    }
    if(ss[0]=='S'){
      if(ss[1]==ss[n-1]){
        if(s[0]=='o'){
          flg = 1;
          break;
        }
      }else{
        if(s[0]=='x'){
          flg = 1;
          break;
        }
      }
    }else{
      if(ss[1]==ss[n-1]){
        if(s[0]=='x'){
          flg = 1;
          break;
        }
      }else{
        if(s[0]=='o'){
          flg = 1;
          break;
        }
      }
    }
  }
  if(flg) cout << ss << endl;
  else cout << "-1" << endl;
}