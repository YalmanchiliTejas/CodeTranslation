#include <iostream>
using namespace std;
int main(){
  int n;cin>>n;
  string s;cin>>s;
  //WW->WS->SW->SS
  char tmp[n];
  for(int q = 0; 4 > q; q++){
    tmp[0] = (q/2 == 0 ? 'W':'S');
    tmp[1] = (q%2 == 0 ? 'W':'S');

    for(int i = 2; s.size() > i; i++){
      if(tmp[i-1]=='W'){
        if(s[i-1]=='o'){
          if(tmp[i-2]=='W')tmp[i]='S';
          else tmp[i]='W';
        }else{
          tmp[i]=tmp[i-2];
        }
      }else{
        if(s[i-1]=='o'){
          tmp[i]=tmp[i-2];
        }else{
          if(tmp[i-2]=='W')tmp[i]='S';
          else tmp[i]='W';
          
        }
      }
      //cout << i << " " << tmp[i] << endl;
    }
    bool ok = false;
    if(s[s.size()-1] == 'o'){
      if(tmp[s.size()-1]=='S'){
        if(tmp[s.size()-2]==tmp[0]){
          ok = true;
        }
      }else{
        if(tmp[s.size()-2]!=tmp[0]){
          ok = true;
        }
      }
    }else{
      if(tmp[s.size()-1]=='S'){
        if(tmp[s.size()-2]!=tmp[0]){
          ok = true;
        }
      }else{
        if(tmp[s.size()-2]==tmp[0]){
          ok = true;
        }
      }
    }
    bool ok2 = false;
    if(ok){
      if(s[0]=='o'){
        if(tmp[0]=='S'){
          if(tmp[s.size()-1]==tmp[1]){
            ok2 = true;
          }
        }else{
          if(tmp[s.size()-1]!=tmp[1]){
            ok2=true;
          }
        }
      }else{
        if(tmp[0]=='S'){
          if(tmp[s.size()-1]!=tmp[1]){
            ok2 = true;
          }
        }else{
          if(tmp[s.size()-1]==tmp[1]){
            ok2 = true;
          }
        }
      }
    }
    if(ok2){
      for(int i = 0; n > i; i++){
        cout <<tmp[i];
      }
      cout << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}