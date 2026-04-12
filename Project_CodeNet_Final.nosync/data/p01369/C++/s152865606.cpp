#if 1
  #include <bits/stdc++.h>
#else
  #include "../../bits/stdc++.h"
#endif

#define FOR(i,a,b) for(int i = (a);i < (b);i++)
#define RFOR(i,a,b) for(int i = (b)-1;i >= (a);i--)
#define REP(i,n) FOR(i,0,(n))
#define RREP(i,n) RFOR(i,0,(n))

using namespace std;

typedef pair<int, int> P;
#define pb push_back
#define mp make_pair
#define ft first
#define sd second

int n;
char s[34];

bool input(){
  cin>>s;
  if(s[0]=='#')return false;
  n = strlen(s);
  return true;
}

bool right(char c) {
  switch(c) {
    case 'y':case 'u':case 'i':case 'o':case'p':
    case 'h':case 'j':case 'k':case 'l':case 'n':case 'm':
    return true;
    break;
  }
  return false;
}

void solve(){
  int c=0;
  bool f=right(s[0]);
  FOR(i, 1, n) {
    if(f!=right(s[i])) {
      c++;
      f=!f;
    }
  }
  cout<<c<<endl;
}

int main(){
  cin.tie(0);
  
  while (input()){
      solve();
  }
  
  return 0;
}