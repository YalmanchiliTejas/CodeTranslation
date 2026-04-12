#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < n;i++)
using ll = long long;

int main(){
  int n,a[27]; cin >>n;
  for(int i = 1; i<=26; i++) a[i]=99999;
  for(int i = 1; i<=n; i++){
    string s; cin >>s;
    int b[27] = {0};
    rep(j,s.size()) b[(s[j]-'a')+1]++;
    for(int j = 1;j<=26;j++) a[j]=min(a[j],b[j]);
  }
  for(int i = 1; i<=26; i++){
    for(int j = 1;j<=a[i]; j++) cout << char(i+'a'-1);
  }
  cout << endl;
  return 0;
}