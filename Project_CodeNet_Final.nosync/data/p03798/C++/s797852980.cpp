#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cassert>
#include<cstring>
#include<climits>
#include<sstream>
#include<deque>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<bitset>
 
#define REP(i,s,n) for(int i=s;i<n;++i)
#define rep(i,n) REP(i,0,n)
 
using namespace std;
 
typedef long long ll;
 
#define MAX_N 100010
 
int n;
string s;
int ans[MAX_N];
 
bool check() {
  rep(i,n) {
    int next = ( i + 1 ) % n;
    int prev = ( i - 1 + n ) % n;
    if( ans[i] == 0 ) {
      if( s[i] == 'o' ) {
	if( !( ans[prev] == ans[next] ) ) return false;
      } else {
	if( !( ans[prev] != ans[next] ) ) return false;
      }
    } else {
      if( s[i] == 'o' ) {
	if( !( ans[prev] != ans[next] ) ) return false;
      } else {
	if( !( ans[prev] == ans[next] ) ) return false;
      }
    }
  }
  return true;
}
 
bool calc(int a,int b) {
  memset(ans,-1,sizeof ans);
  ans[0] = a, ans[1] = b;
  REP(i,1,n-1) {
    int next = ( i + 1 ) % n;
    int prev = ( i - 1 + n ) % n;
    if( s[i] == 'o' ) {
      if( ans[i] == 0 ) {
	ans[next] = ans[prev];
      } else {
	ans[next] = (ans[prev]+1)%2;
      }
    } else {
      if( ans[i] == 0 ) {
	ans[next] = (ans[prev]+1)%2;
      } else {
	ans[next] = ans[prev];
      }
    }
  }
  return check();
}
 
void compute() {
  rep(i,2) {
    rep(j,2) {
      if( calc(i,j) ) {
	rep(k,n) {
	  if( ans[k] == 0 ) cout << "S";
	  else cout << "W";
	} puts("");
	return;
      }
    }
  }
  puts("-1");
}
 
int main() {
  cin >> n >> s;
  compute();
  return 0;
}