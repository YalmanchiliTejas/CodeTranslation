#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;cin>>n;
  vector<map<char,int>>a(n);
  string tmp;
  for(int i=0;i<n;i++){
    cin>>tmp;
    int size=tmp.size();
    for(int j=0;j<size;j++){
      if(a.at(i).count(tmp.at(j)))a.at(i).at(tmp.at(j))++;
      else a.at(i)[tmp.at(j)]=1;
    }
    if(i!=0){
      for(auto w:a.at(i)){
        if(a.at(0).count(w.first))a.at(0).at(w.first)=min(a.at(0).at(w.first),w.second);
      }
      for(auto w:a.at(0)){
        if(!a.at(i).count(w.first))a.at(0).at(w.first)=0;
      }
    }  
  }
  for(int i=0;i<26;i++){
    if(a.at(0).count((char)(int)'a'+i)){
      for(int j=0;j<a.at(0).at((char)(int)'a'+i);j++){
        cout <<(char)(int)('a'+i);
      }
    }
  }
  cout <<endl;
}