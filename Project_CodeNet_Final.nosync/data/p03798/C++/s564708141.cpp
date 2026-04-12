#include <bits/stdc++.h>
using namespace std;

int main(){
  long long N; cin >> N;
  string s; cin >> s;
  string first[4]={"SS","SW","WS","WW"};
  string res="";
  for(int i=0; i<4; i++){
    //初期
    res=first[i];
    //N文字作成
    for(int j=2; j<N; j++){
      if(res[j-1]=='S'){
        if(s[j-1]=='o'){
          if(res[j-2]=='S') res+="S";
          else res+="W";
        }else{
          if(res[j-2]=='S') res+="W";
          else res+="S";
        }
      }else{
        if(s[j-1]=='o'){
          if(res[j-2]=='S') res+="W";
          else res+="S";
        }else{
          if(res[j-2]=='S') res+="S";
          else res+="W";
        }
      }
    }
    //チェック（1・N文字目を調べる必要があり）
    bool isOK=true;
    if(res[0]=='S'){
      if(s[0]=='o'){
        if(res[N-1]!=res[1]) isOK=false;
      }else{
        if(res[N-1]==res[1]) isOK=false;
      }
    }else{
      if(s[0]=='o'){
        if(res[N-1]==res[1]) isOK=false;
      }else{
        if(res[N-1]!=res[1]) isOK=false;
      }
    }
    if(res[N-1]=='S'){
      if(s[N-1]=='o'){
        if(res[N-2]!=res[0]) isOK=false;
      }else{
        if(res[N-2]==res[0]) isOK=false;
      }
    }else{
      if(s[N-1]=='o'){
        if(res[N-2]==res[0]) isOK=false;
      }else{
        if(res[N-2]!=res[0]) isOK=false;
      }
    }
    if(isOK==true){
      break;
    }else{
      res="";
    }
  }
  if(res.size()>0){
    cout << res << endl;
  }else{
    cout << -1 << endl;
  }
}