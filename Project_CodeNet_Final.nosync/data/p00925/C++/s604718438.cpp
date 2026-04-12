#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  int n;
  cin >> s >> n;

  stack<int> t;
  t.push(s[0]-'0');
  for(int i=1;i<s.size();i+=2){
    int tmp = s[i+1]-'0';
    if(s[i] == '*')t.top() *= tmp;
    else t.push(tmp);
  }
  int M = 0;
  while(t.size()){
    M += t.top(), t.pop();
  }

  int L = s[0]-'0';
  for(int i=1;i<s.size();i+=2){
    int tmp = s[i+1]-'0';
    if(s[i] == '*')L *= tmp;
    else L += tmp;
  }

  if(M == n && L == n)cout << "U";
  else if(M == n)cout << "M";
  else if(L == n)cout << "L";
  else cout << "I";
  cout << endl;
}