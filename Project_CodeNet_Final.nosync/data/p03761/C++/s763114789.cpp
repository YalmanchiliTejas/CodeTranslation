#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<string> S(n);
  for (int i=0;i<n;i++){
    cin >> S[i];
  }
  string A="abcdefghijklmnopqrstuvwxyz";
  map<char,int> m;
  for (int i=0;i<26;i++){
    m[A[i]]=51;
  }
  for (int i=0;i<n;i++){
    map<char,int> mx;
    int s=S[i].size();
    for (int j=0;j<s;j++){
      mx[S[i][j]]++;
    }
    for (int j=0;j<26;j++){
      m[A[j]]=min(m[A[j]],mx[A[j]]);
    }
  }
  string ans="";
  for (int i=0;i<26;i++){
    for (int j=0;j<m[A[i]];j++){
      ans+=A[i];
    }
  }
  cout << ans << endl;
}