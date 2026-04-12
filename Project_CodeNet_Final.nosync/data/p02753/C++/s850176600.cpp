#include <bits/stdc++.h>
using namespace std; 
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ll long long
long long min(long long x,long long y){return (x<y ? x:y);}
long long max(long long x,long long y){return (x>y ? x:y);}
#define ld long double
int stoi(string s) {return atoi(s.c_str());}

int main(){
  string s; cin >> s;
  bool a = false;
  bool b = false;
  REP(i,3){
    if(s[i]=='A'){a =true;}
    else{b=true;}
  }
  if(a*b){cout << "Yes\n";}
  else{cout << "No\n";}
  
}