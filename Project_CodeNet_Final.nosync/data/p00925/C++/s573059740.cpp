#include <bits/stdc++.h>

using namespace std;

int left_first(string s) {
  int res=s[0]-'0';
  for(int i=1;i<s.size();i+=2) {
    if(s[i]=='*') res*=s[i+1]-'0';
    else res+=s[i+1]-'0';
  }
  return res;
}

int multi_first(string s) {
  stack<int> sdig;
  for(int i=0;i<s.size();++i) {
    if(s[i]=='*') {
      int tmp=sdig.top(); sdig.pop();
      sdig.push(tmp*(s[i+1]-'0'));
      i++;
    } else if(isdigit(s[i])) sdig.push(s[i]-'0');
  }
  int res=0;
  while(!sdig.empty()) {
    res+=sdig.top(); sdig.pop();
  }
  return res;
}

int main(){
  string s; cin >> s;
  int a; cin >> a;
  int le=left_first(s);
  int mu=multi_first(s);
  if(le==a&&mu==a) cout << "U";
  else if(le==a) cout << "L";
  else if(mu==a) cout << "M";
  else cout << "I";
  cout << endl;
  
  return 0;
}
