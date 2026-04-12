#include<bits/stdc++.h>
using namespace std;
string t="qazwsxedcrfvtgb";
int tp(string s){
  int rl=0,cnt=0;
  if(t.find(s[0])!=string::npos) rl=1;
  for(int i=1;i<s.size();++i)
    if(t.find(s[i])==string::npos && rl==1) cnt++, rl=0;
    else if(t.find(s[i])!=string::npos && rl==0) cnt++, rl=1;
  return cnt;
}
int main(){
  string s;
  while(cin>>s, s!="#")
    cout<<tp(s)<<endl;
  return 0;
}