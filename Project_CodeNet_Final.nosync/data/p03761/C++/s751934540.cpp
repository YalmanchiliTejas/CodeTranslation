#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> coms(26), chars(26);
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    fill(chars.begin(),chars.end(),0);
    string s;
    cin>>s;
    for(int j=0;j<s.size();j++){
      int c=s.at(j)-97;
      chars.at(c)++;
    }
    if(i==0){
      coms=chars;
      continue;
    }else{
      for(int j=0;j<26;j++){
        if(coms.at(j)!=chars.at(j)){coms.at(j)=min(coms.at(j),chars.at(j));}
      }
    }
  }
  for(int i=0;i<coms.size();i++){
    char c=i+97;
    int cnt=coms.at(i);
    for(int j=0;j<cnt;j++){
      cout<<c;
    }
  }
  cout<<endl;
}