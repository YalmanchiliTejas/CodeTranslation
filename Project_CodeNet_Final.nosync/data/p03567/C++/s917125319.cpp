#include <bits/stdc++.h>
using namespace std;
int main(){
  string S;
  cin>>S;
  bool A=false;
  for(int i=0;i<S.size();i++){
    if(A==false&&S.at(i)=='A'){
      A=true;
      continue;
    }
    if(A==true&&S.at(i)=='C'){
      cout<<"Yes"<<endl;
      break;
    }
    if(A==true&&S.at(i)!='C')A=false;
    if(i==S.size()-1)cout<<"No"<<endl;
  }
}