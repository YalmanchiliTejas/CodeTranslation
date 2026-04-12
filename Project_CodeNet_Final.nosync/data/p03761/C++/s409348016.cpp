#include<bits/stdc++.h>
using namespace std;
int a[50][26];
int b[26];
int main(){
  int n;
  cin >>n;
  vector<string> s(n);
  for(int i=0;i<n;i++){
    cin >>s[i];
    for(int j=0;j<s[i].size();j++){
      for(int k=0;k<26;k++){
        if(s[i][j]=='a'+k)a[i][k]++;
      }
    }
  }
  for(int i=0;i<26;i++)b[i]=a[0][i];
  for(int i=0;i<26;i++){
    for(int j=1;j<n;j++)b[i]=min(b[i],a[j][i]);
  }
  for(int j=0;j<26;j++)cerr<<a[2][j]<<endl;
  string t;
  t="";
  for(int i=0;i<26;i++){
    for(int j=0;j<b[i];j++)t+=(char)'a'+i;
  }
  cout << t <<endl;
}