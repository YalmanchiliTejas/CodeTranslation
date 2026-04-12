#include <bits/stdc++.h>
using namespace std;
int32_t main()
{
  int n;
  cin >> n;
  string s;
  cin >> s;
  int k;
  cin >> k;
  char ch = s[k-1];
  string ans="";
  for(int i=0;i<n;i++){
      if(s[i]!=ch){
          s[i]='*';
      }
  }
  cout<<s<<"\n";


}
