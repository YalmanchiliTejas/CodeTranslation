#include <bits/stdc++.h>
using namespace std;

int main(){
  int h,w; cin>>h>>w;
  int count=0;
  vector<string> s(h);
  for(int i=0;i<h;i++){
    string str; cin>>str;
    bool flag=false;
    for(int j=0;j<w;j++){
      if(str[j]=='#'){
        flag = true;
        break;
      }
    }
    if(flag){
      s[count]=str;
      count++;
    }
  }
  vector<int> skip;
  for(int i=0;i<w;i++){
    for(int j=0;j<count;j++){
      if(s[j][i]=='#') break;
      if(j==count-1) skip.push_back(i);
    }
  }
  for(int i=0;i<count;i++){
    for(int j=0;j<w;j++){
      bool flag = true;
      for(int k=0;k<skip.size();k++){
        if(skip[k]==j) flag=false;
      }
      if(flag) cout<<s[i][j];
    }
    cout<<endl;
  }
}