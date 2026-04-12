#include<iostream>
using namespace std;

int main(){
  string l="qazwsxedcrfvtgb";
  string r="yhnujmikolp";
  while(1){
    string s;
    cin>>s;
    if(s[0]=='#')break;
    int sta=0;
    for(int i=0;i<l.size();i++){
      if(s[0]==l[i])sta=1;
    }
    int ans=0;
    for(int j=0;j<s.size();j++){
      if(sta==0){
        for(int i=0;i<l.size();i++){
          if(s[j]==l[i]){
            sta=1;
            ans++;
          }
        }
      }else{
        for(int i=0;i<r.size();i++){
          if(s[j]==r[i]){
            sta=0;
            ans++;
          }
        }
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}