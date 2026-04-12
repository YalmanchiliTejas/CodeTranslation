#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  vector<string> s(n);
  for(int i=0;i<n;i++){
    cin>>s[i];
    sort(s[i].begin(),s[i].end());
  }
  vector<vector<int>> data(n, vector<int>(26));
  for(int i=0;i<n;i++){
    for(int j=0;j<s[i].size();j++){
      int num=s[i][j]-'a';
      data[i][num]++;
    }
  }
  string ans="";
  for(int i=0;i<26;i++){
    int mini=12345;
    for(int j=0;j<n;j++){
      mini=min(data[j][i],mini);
    }
    for(int k=0;k<mini;k++){
      ans+=char(i+'a');
    }
  }
cout<<ans<<endl;
}
