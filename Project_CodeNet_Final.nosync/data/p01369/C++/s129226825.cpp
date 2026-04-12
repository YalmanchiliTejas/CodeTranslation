#include<bits/stdc++.h>
using namespace std;
int main(){
  string l="qazwsxedcrfvtgb";
  string r="yhnujmikolp";
  while(1){
    string s;
    cin >> s;
    if(s[0]=='#') break;
    int str = 0;
    for(int i=0; i<(int)l.size(); i++){
      if(s[0]==l[i]) str=1;
    }
    int ans = 0;
    for(int i=0; i<(int)s.size(); i++){
      if(str==0){
        for(int j=0; j<(int)l.size(); j++){
          if(s[i]==l[j]){
            str=1;
            ans++;
          }
        }
      }
      else{
        for(int j=0; j<(int)r.size(); j++){
          if(s[i]==r[j]){
            str=0;
            ans++;
          }
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}

