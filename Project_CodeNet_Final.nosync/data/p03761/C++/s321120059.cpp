#include<bits/stdc++.h>
using namespace std;
int main (){
  int n;
  cin >> n;
  vector<string> s(n);
  for(int i=0;i<n;i++){
    cin >> s[i];
  }
  int c[27][n];
  for(int i=0;i<27;i++)
    for(int j=0;j<n;j++)
      c[i][j]=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<s[i].size();j++)
      c[s[i][j]-'a'][i]++;
  }
  string ans;
  for(int i=0;i<27;i++){
    int num=1000000;
    for(int j=0;j<n;j++){
      num = min(num,c[i][j]);
    }
    for(int j=0;j<num;j++){
      ans+=('a'+i);
    }
  }
  cout<<ans<<endl;
  return 0;
}
