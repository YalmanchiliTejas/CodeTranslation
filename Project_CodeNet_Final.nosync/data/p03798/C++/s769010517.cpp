#include<bits/stdc++.h>
using namespace std;
char negate_(char x) {
  return x=='S'?'W':'S';
}
bool test(string& ox, string& sw){
  for(int i=0;i<ox.size();++i){
    int left=(ox.size()+i-1)%ox.size();
    int right=(i+1)%ox.size();
    if(sw[i]=='S'&&ox[i]=='o'||sw[i]=='W'&&ox[i]=='x'){
      if(sw[left]=='?'){
        sw[left]=sw[right];
      }else if(sw[right]=='?'){
        sw[right]=sw[left];
      }else{
        if (sw[left]!=sw[right])return false;
      }
    }else{
      if(sw[left]=='?'){
        sw[left]=negate_(sw[right]);
      }else if(sw[right]=='?'){
        sw[right]=negate_(sw[left]);
      }else{
        if (sw[left]==sw[right])return false;
      }
    }
  }
  return true;
}
main(){
  int N;
  string s;
  cin>>N>>s;
  string sw;
  bool done=false;
  auto f=[&s,&sw,&done](char c0, char c1){
    if(done)return;
    sw=string(s.size(),'?');
    sw[0]=c0;
    sw[1]=c1;
    if(test(s,sw)){
      cout<<sw<<endl;
      done=true;
    }
  };
  f('S','S');
  f('S','W');
  f('W','S');
  f('W','W');
  if(!done)cout<<-1<<endl;
}
