#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  int alp[26];
  for(int i=0; i<26; i++){
    alp[i]=100;
  }
  
  string s;
  for(int i=0; i<n; i++){
    cin >> s;
    
    int cur[26]={};
    for(int j=0; j<s.size(); j++){
      cur[s[j]-'a']++;
    }
    
    for(int j=0; j<26; j++){
      alp[j]=min(alp[j],cur[j]);
    }
  }
  
  for(int i=0; i<26; i++){
    if(alp[i]!=0){
      for(int j=0; j<alp[i]; j++){
        cout << (char)(i+'a');
      }
    }
  }
  cout << endl;
}