#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  vector<string> S(60);
  cin >> n;
  for(int i=0;i<n;i++)cin >> S[i];
  string ans="";
  for(int i=0;i<=25;i++){
    char X='a'+i; int q=50;
    for(int j=0;j<n;j++){
      int count=0;
      for(int k=0;k<S[j].size();k++){
        if(S[j][k]==X){count++;}
      }
      q=min(q,count);
    }
    for(int l=0;l<q;l++)ans+=X;
  }
  cout << ans << endl;
}