#include <bits/stdc++.h>
using namespace std;

int mba(string s){
  vector<int> t;
  t.push_back(s[0] - '0');
  for(int i = 1; i < s.size() ; i+=2){
    if(s[i]=='+'){
      t.push_back(s[i+1] - '0');
    } else {
      t.back() *= s[i+1] - '0';
    }
  }
  int res = 0;
  for(int i : t)res += i;
  return res;
}
int ltr(string s){
  int res = s[0] - '0';
  for(int i = 1; i < s.size() ; i+=2){
    if(s[i]=='+'){
      res += s[i+1] - '0';
    } else {
      res *= s[i+1] - '0';
    }
  }
  return res;
}
int main(){
  string out = "IMLU";
  string s; cin >> s;
  int e; cin >> e;
  cout << out[(mba(s)==e) + 2*(ltr(s)==e)] << endl;
}