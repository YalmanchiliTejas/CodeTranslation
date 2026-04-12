#include <bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i<n;++i)
using ll = long long;
using P = pair<int,int>;

int main(){
  string s;
  cin >> s;
  bool flag = false;
  if(s == "a") flag = true;
  if(s == "i") flag = true;
  if(s == "u") flag = true;
  if(s == "e") flag = true;
  if(s == "o") flag = true;
  if(!flag) puts("consonant");
  else puts("vowel");
  return 0;
}
