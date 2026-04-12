#include <iostream>
using namespace std;
bool right(char c){
  string r = "qwertasdfgzxcvb";
  for(int i=0;i<r.length();++i) if(c==r[i]) return true;
  return false;
}
bool left(char c){
  string l = "yuiophjklnm";
  for(int i=0;i<l.length();++i) if(c==l[i]) return true;
  return false;
}
int solve(string s){
  int cnt = 0;
  for(int i=0;i+1<s.length();++i){
    if(right(s[i])&&left(s[i+1])) ++cnt;
    else if(left(s[i])&&right(s[i+1])) ++cnt;
  }  
  return cnt;
}
int main(){
  string s;
  while(cin>>s,s!="#")
    cout << solve(s) << endl;
  return 0;
}