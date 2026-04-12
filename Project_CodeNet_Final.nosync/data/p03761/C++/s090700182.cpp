#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  int i,j,k,cnt;
  int n;
  cin>>n;
  string s[n];
  for(i=0;i<n;i++)cin>>s[i];
  int m[26];
  for(i=0;i<26;i++)m[i]=INT_MAX;
  for(i=0;i<26;i++){
    for(j=0;j<n;j++){
      cnt=0;
      for(k=0;k<s[j].size();k++){
        if(s[j][k]=='a'+i)cnt++;
      }
      m[i]=min(m[i],cnt);
    }
  }
  string sum="";
  for(i=0;i<26;i++){
    for(j=0;j<m[i];j++){
      sum+=(char)('a'+i);
    }
  }
  cout<<sum;
}