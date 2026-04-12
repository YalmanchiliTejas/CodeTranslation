#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  int vec[n][26]={};
  string q="abcdefghijklmnopqrstuvwxyz";
  for(int i=0;i<n;i++){
    string s;
    cin>>s;
    for(int j=0;j<s.size();j++){
      for(int k=0;k<26;k++){
        if(s[j]==q[k]){
          vec[i][k]++;
        }
      }
    }
  }
  for(int i=0;i<26;i++){
    int z=500;
    for(int j=0;j<n;j++){
      z=min(z,vec[j][i]);
    }
    for(int j=0;j<z;j++){
      cout<<q[i];
    }
  }
  cout<<endl;
}