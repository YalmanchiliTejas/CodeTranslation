#include<iostream>
#include<cstdio>
#include<cstring>
#include<climits>
#include<cassert>
#include<cmath>
#include<cstdlib>
#include<complex>
#include<algorithm>
#include<vector>
#include<deque>
#include<queue>
#include<map>
#include<set>
#include<sstream>
#include<bitset>

#define REP(i,s,n) for(int i=s;i<n;i++)
#define rep(i,n) REP(i,0,n)

using namespace std;

typedef long long ll;
#define IINF INT_MAX
#define LLINF LLONG_MAX

int main(){
  string s,t;
  cin >> s >> t;
  vector<int> a,b;
  int ptr = 0;
  rep(i,(int)s.size()) {
    if( s[i] == t[ptr] ) {
      a.push_back(i);
      ++ptr;
      if( ptr >= (int)t.size() ) break;
    }
  }
  if( ptr < (int)t.size() ) { puts("no"); return 0; }
  ptr = (int)t.size()-1;
  for(int i=(int)s.size();i>=0;--i) {
    if( s[i] == t[ptr] ) {
      b.push_back(i);
      --ptr;
      if( ptr < 0 ) break;
    }
  }
  reverse(b.begin(),b.end());
  puts((a==b)?"yes":"no");
  return 0;
}