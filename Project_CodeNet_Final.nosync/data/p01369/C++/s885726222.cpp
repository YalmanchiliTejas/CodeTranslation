#include<bits/stdc++.h>
using namespace std;
string t[]={"qazwsxedcrfvtgb","yhnujmikolp"};
int tp(string s){
  int rl,cnt=0;
  for(int i=0;i<2;++i)
    if(t[i].find(s[0])!=string::npos) rl=i;
  for(int i=1;i<s.size();++i)
    for(int j=0;j<2;++j)
      if(t[j].find(s[i])!=string::npos)
        if(j!=rl) cnt++, rl=j;
  return cnt;
}
int main(){
  string s;
  while(cin>>s, s!="#"){
    cout<<tp(s)<<endl;
  }
  return 0;
}