#include <bits/stdc++.h>
using namespace std;

int main(){
  //cout<<'z'-'a'<<endl;
  int n;
  cin>>n;
  int ch[26];
  int chmax[26];
  for(int i=0;i<26;i++){
    ch[i]=0;
  }
  for(int i=0;i<26;i++){
    chmax[i]=50;
  }
  string s[n];
  
  for (int i=0;i<n;i++){
    cin>>s[i];
    for(int j='a';j<='z';j++){
      ch[j-'a']=0;
      for(int k=0;k<s[i].length();k++){
        if(s[i].at(k)==j){
          ch[j-'a']++;
        }
      }
      chmax[j-'a']=min(chmax[j-'a'],ch[j-'a']);
    }
  }

  for(int i=0;i<26;i++){
    cout<<string(chmax[i],'a'+i);
  }
  cout<<endl;
  return 0;
}

  