#include<bits/stdc++.h>
using namespace std;
int main(){int c=0;
  string s;
  cin>>s;
  c=count(s.begin(),s.end(),s[0]);
  if(c==3) cout<<"No";
  else cout<<"Yes";
return 0;
}