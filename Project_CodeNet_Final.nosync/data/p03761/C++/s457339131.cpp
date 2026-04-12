#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <set>
#include <iomanip>
#include <stdio.h>
#include <sstream>
#include <string>
#include <bits/stdc++.h>
using namespace std;
int main(void){
  int n;
  cin>>n;
  vector<string> s(n);
  vector<map<char,int>> hoge(n);
  for(int i=0; i<n; i++){
    cin>>s.at(i);
    sort(s.at(i).begin(),s.at(i).end());
  }
  string ans="";
  char now='a';
  while(now<='z'){
    bool ok=true;
    for(int i=0; i<n; i++){
      if(s.at(i)[0]!=now){
        ok=false;
      }
    }
    if(ok){
      for(int i=0; i<n; i++){
        s.at(i).erase(s.at(i).begin());
      }
      ans+=now;
    }else{
      for(int i=0; i<n; i++){
        for(int j=0; j<s.at(i).size(); j+=0){
          if(s.at(i)[0]==now){
            s.at(i).erase(s.at(i).begin());
          }else{
            break;
          }
        }
      }
      now+=1;
    }
  }
  cout<<ans<<endl;
}