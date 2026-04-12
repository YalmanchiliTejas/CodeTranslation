#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL_DEBUG
  #include "LOCAL_DEBUG.hpp"
#endif
#define int long long

signed main(){

  int n; cin >> n;
  string s; cin >> s;

  vector<char> t(n);
  for(char c1 : {'S','W'}){
    for(char c2 : {'S','W'}){
      t[0] = c1;
      t[1] = c2;
      for(int i = 2; i < n; i++){
        if(s[i-1] == 'o'){
          if(t[i-1] == 'S'){
            if(t[i-2] == 'S') t[i] = 'S';
            else t[i] = 'W';
          }
          else {
            if(t[i-2] == 'S') t[i] = 'W';
            else t[i] = 'S';
          }
        }
        else {
          if(t[i-1] == 'S'){
            if(t[i-2] == 'W') t[i] = 'S';
            else t[i] = 'W';
          }
          else {
            if(t[i-2] == 'W') t[i] = 'W';
            else t[i] = 'S';
          }
        }
      }
      if(s[n-1] == 'o' && (t[n-1] == 'S' && t[n-2] == t[0] || t[n-1] == 'W' && t[n-2] != t[0]) || s[n-1] == 'x' && (t[n-1] == 'S' && t[n-2] != t[0] || t[n-1] == 'W' && t[n-2] == t[0])){
        if(s[0] == 'o' && (t[0] == 'S' && t[n-1] == t[1] || t[0] == 'W' && t[n-1] != t[1])  || s[0] == 'x' && (t[0] == 'S' && t[n-1] != t[1] || t[0] == 'W' && t[n-1] == t[1]) ){
          for(int j = 0; j < n; j++){
            cout << t[j];
          }
          cout << endl;
          return 0;
        }
      }
    }
  }
  cout << -1 << endl;

  return 0;
}
