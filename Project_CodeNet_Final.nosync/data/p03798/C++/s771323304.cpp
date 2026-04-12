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
  sw=string(s.size(),'?');
  sw[0]='S';
  sw[1]='S';
  if(test(s,sw)){
    cout<<sw<<endl;
    return 0;
  }
  sw=string(s.size(),'?');
  sw[0]='S';
  sw[1]='W';
  if(test(s,sw)){
    cout<<sw<<endl;
    return 0;
  }
  sw=string(s.size(),'?');
  sw[0]='W';
  sw[1]='S';
  if(test(s,sw)){
    cout<<sw<<endl;
    return 0;
  }
  sw=string(s.size(),'?');
  sw[0]='W';
  sw[1]='W';
  if(test(s,sw)){
    cout<<sw<<endl;
    return 0;
  }
  cout<<-1<<endl;
}
