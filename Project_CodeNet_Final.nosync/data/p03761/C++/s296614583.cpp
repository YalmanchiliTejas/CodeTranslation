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
    int count=10000;
    for(int i=0; i<n; i++){
      int precount=0;
      for(int j=0; j<s.at(i).size(); j++){
        if(s.at(i)[j]==now){
          precount++;
        }
      }
      count=min(count,precount);
    }
    for(int i=0; i<count; i++){
        ans+=now;
      }
    now+=1;
  }
  cout<<ans<<endl;
}