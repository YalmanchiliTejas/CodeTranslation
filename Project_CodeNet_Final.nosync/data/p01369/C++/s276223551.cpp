#include <bits/stdc++.h>

using namespace std;

int judge(char c){
  int a;
  switch (c){
  case 'y':
  case 'h':
  case 'n':
  case 'u':
  case 'j':
  case 'm':
  case 'i':
  case 'k':
  case 'o':
  case 'l':
  case 'p':
    a=1;
    break;
  default:
    a=0;
    break;
  }
  return a;
}

int main() {
  string s;
  while(cin >> s && s!="#"){
    int cnt=0,b=judge(s[0]);
    for(int i=0;i<s.size();++i){
      if(judge(s[i])!=b) {
	cnt++;
	b=judge(s[i]);
      }
    }
    cout << cnt << endl;
  }
  
  return 0;
}
