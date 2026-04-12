#include <bits/stdc++.h>
#define INF LLONG_MAX
#define ll  long long
#define ull unsigned long long
#define rep(i,n) for(int i=0; i<n; ++i)
#define MOD 1000000007
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if(a>b) {a=b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) { if(a<b) {a=b; return true;} return false;}

string burger;
ll rec(ll N, ll X) {
  if(N==0) return 1;
  ll len = (1LL<<(N+1)) - 3;
  ll num = (1LL<<N) - 1;
  if(X==1) return 0;
  if(X<=len+1) return rec(N-1, X-1);
  if(X==len+2) return num+1;
  if(X<=(len+1)*2) return num+1+rec(N-1,X-len-2);
  return num*2+1;
}

int main() {
  ll N, X; cin >> N >> X;
  cout << rec(N, X) << endl;
}