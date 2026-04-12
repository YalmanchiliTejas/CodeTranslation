#include <bits/stdc++.h>
using namespace std;

int main() {
  long n;
  string ans="";
  cin >> n;
  vector<vector<long>> a(26,vector<long>(n));
  vector<string> s(n);
  for(long i=0;i<n;i++) cin >> s[i];
  for(long i=0;i<n;i++) {
    for(long j=0;j<s[i].size();j++) {
      a[s[i][j]-'a'][i]++;
    }
  }
  for(char i='a';i<='z';i++) {
    sort(a[i-'a'].begin(),a[i-'a'].end());
    for(long j=0;j<a[i-'a'][0];j++) ans=ans+i;
  }
  cout << ans << endl;
}