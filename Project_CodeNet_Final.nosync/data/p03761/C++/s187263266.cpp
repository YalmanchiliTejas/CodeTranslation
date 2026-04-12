#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;cin>>n;
  int alfa[n][30]={};
  for(int i=0;i<n;i++){
    string s;cin>>s;
    for(int j=0;j<s.size();j++){
      alfa[i][s[j]-'a']++;
    }
  }
  for(int i=0;i<26;i++){
    int mi=1000000000;
    for(int j=0;j<n;j++){
      mi=min(mi,alfa[j][i]);
    }
    for(int j=0;j<mi;j++)
      cout<<(char)(i+'a');
  }
  cout<<endl;
  return 0;
}
