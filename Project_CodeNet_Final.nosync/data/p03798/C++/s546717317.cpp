#include <bits/stdc++.h>
using namespace std;

long n;
string s,ans;

string test(string a) {
  while(a.size()!=n) {
    if(a.substr(a.size()-2,2)=="SS") {
      if(s[a.size()-1]=='o') a+="S";
      else a+="W";
    } else if(a.substr(a.size()-2,2)=="SW") {
      if(s[a.size()-1]=='o') a+="W";
      else a+="S";
    } else if(a.substr(a.size()-2,2)=="WS") {
      if(s[a.size()-1]=='o') a+="W";
      else a+="S";
    } else {
      if(s[a.size()-1]=='o') a+="S";
      else a+="W";
    }
  }
  return a;
}

void aaa(string b) {
  ans=test(b);
  bool x=false;
  if(ans[0]=='S') {
    if(s[0]=='o'&&ans.back()!=ans[1]) x=true;
    if(s[0]=='x'&&ans.back()==ans[1]) x=true;
  } else {
    if(s[0]=='x'&&ans.back()!=ans[1]) x=true;
    if(s[0]=='o'&&ans.back()==ans[1]) x=true;
  }
  if(ans.back()=='S') {
    if(s.back()=='o'&&ans[n-2]!=ans[0]) x=true;
    if(s.back()=='x'&&ans[n-2]==ans[0]) x=true;
  } else {
    if(s.back()=='x'&&ans[n-2]!=ans[0]) x=true;
    if(s.back()=='o'&&ans[n-2]==ans[0]) x=true;
  }
  if(x) ans="-1";
  return;
}

int main() {
  cin >> n >> s;
  aaa("SS");
  if(ans=="-1") aaa("SW");
  if(ans=="-1") aaa("WS");
  if(ans=="-1") aaa("WW");
  cout << ans << endl;
}