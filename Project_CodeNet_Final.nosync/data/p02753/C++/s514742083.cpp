#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >>S;
  bool s = false;
  for (int i =0;i<2;i++){
    if(S.at(i) != S.at(i+1)){      
      s = true;
      break;
    }
    }
  if(s){
    cout <<"Yes"<<endl;
  }
  else{
    cout <<"No"<<endl;
  }
  }












