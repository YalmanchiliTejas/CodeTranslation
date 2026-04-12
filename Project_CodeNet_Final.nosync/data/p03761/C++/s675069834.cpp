#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<string> s(n);
  vector<int> c(26),t(26);
  for(int i=0;i<26;i++){
    t[i]=51;
  }
  for(int i=0;i<n;i++){
    cin >> s[i];
    for(int j=0;j<s[i].size();j++){
      c[s[i][j]-'a']++;
    }
    for(int j=0;j<26;j++){
      t[j]=min(t[j],c[j]);
      c[j]=0;
    }
  }
  for(int i=0;i<26;i++){
    if(t[i]!=51){
      for(int j=0;j<t[i];j++){
        cout << char('a'+i);
      }
    }
  }
  cout << endl;
}