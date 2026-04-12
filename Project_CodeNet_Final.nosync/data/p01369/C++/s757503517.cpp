#include<iostream>
#include<string>

using namespace std;

bool is_left(char c){
  string s = "qwertasdfgzxcvb";
  for(int i=0;i<s.size();i++)
    if(s[i]==c)return true;
  return false;
}

int main(void){

  string s;
  while(cin >> s, s!="#"){
    int cnt = 0;
    for(int i=0;i+1<s.size();i++){
      cnt += is_left(s[i])!=is_left(s[i+1]);
    }
    cout << cnt << endl;
  }
  
  return 0;
}