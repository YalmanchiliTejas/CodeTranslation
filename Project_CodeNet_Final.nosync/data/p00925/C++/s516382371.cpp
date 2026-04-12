#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<(n);i++)
#define all(v) (v).begin(),(v).end()
#define pb(a) push_back(a)
using namespace std;
typedef long long LL;

int main(){
  string s;cin >> s;
  int n;cin >> n;
  int a=s[0]-'0';
  for(int i=1;i<s.length();i+=2){
    if(s[i]=='+') a+=s[i+1]-'0';
    else a*=s[i+1]-'0';
  }
  int b=0,t=1;
  bool c=false;
  for(int i=1;i<s.length();i+=2){
    if(s[i]=='+'){
      if(c){
        b+=t*(s[i-1]-'0');
      }
      else b+=s[i-1]-'0';
      t=1;
    }
    else if(s[i]=='*'){
      c=true;
      t*=s[i-1]-'0'; 
    }
  }
  b+=(s[s.length()-1]-'0')*t;
  if(n==a&&n==b) puts("U");
  else if(n==a&&n!=b) puts("L");
  else if(n!=a&&n==b) puts("M");
  else puts("I");
  return 0;
}

