#include<bits/stdc++.h>
using namespace std;
int n,c[30][55];
string s;
int main(){
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>s;
    for(int j=0;j<s.size();j++) c[s[j]-'a'][i]++;
  }
  for(int i=0;i<=25;i++){
    int m=1000000000;
    for(int j=0;j<n;j++) m=min(m,c[i][j]);
    for(int j=1;j<=m;j++) cout<<(char)('a'+i);
  }
  return 0;
}