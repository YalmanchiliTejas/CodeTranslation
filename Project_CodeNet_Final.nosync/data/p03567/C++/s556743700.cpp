#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  bool ans=false;
  cin >>s;
  for(int i=0;i<s.size()-1;i++){
    if (s.at(i)=='A' && s.at(i+1)=='C'){
      ans=true;
    }}
    if (ans){
      cout <<"Yes"<<endl;
    }
    else{
      cout <<"No"<<endl;
    }}
