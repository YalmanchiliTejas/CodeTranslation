#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0;i<n;i++)

int main() {
  string s;
  cin>>s;
  cout<<(s[0]==s[1]&&s[1]==s[2] ? "No":"Yes")<<endl;
  return 0;
}