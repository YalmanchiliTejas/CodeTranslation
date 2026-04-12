#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,array[50][26]={},minal[26];
  string s[50];
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>s[i];
    for(int j=0;j<s[i].size();j++){
      for(char c='a';c<='z';c++){
        if(c==s[i][j]){
          array[i][c-'a']++;
          break;
        }
      }
    }
  }
  for(char c='a';c<='z';c++){
    minal[c-'a']=1e9;
    for(int i=0;i<n;i++){
      minal[c-'a']=min(array[i][c-'a'],minal[c-'a']);
    }
    for(int i=0;i<minal[c-'a'];i++){
      cout<<c;
    }
  }
  cout<<endl;
}