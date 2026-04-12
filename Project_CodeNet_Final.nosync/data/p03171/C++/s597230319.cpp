#include <bits/stdc++.h>
using namespace std;
#define _MACRO(_1, _2, _3, NAME, ...) NAME
#define _repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define _rep(i,n) _repl(i,0,n)
#define rep(...) _MACRO(__VA_ARGS__, _repl, _rep)(__VA_ARGS__)
#define pb push_back
#define all(x) begin(x),end(x)
#define uniq(x) sort(all(x)),(x).erase(unique(all(x)),end(x))
#ifdef LOCAL
#define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
void _dbg(string){cerr<<endl;}
template<class H,class... T> void _dbg(string s,H h,T... t){int l=s.find(',');cerr<<s.substr(0,l)<<" = "<<h<<", ";_dbg(s.substr(l+1),t...);}
template<class T,class U> ostream& operator<<(ostream &o, const pair<T,U> &p){o<<"("<<p.first<<","<<p.second<<")";return o;}
template<class T> ostream& operator<<(ostream &o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}
#else
#define dbg(...) {}
#endif

int a[3005];

bool visited[3005][3005];
long memo[3005][3005];

long solve(int l, int r, bool turn){
  if(l==r) return 0;
  if(visited[l][r]) return memo[l][r];

  long lv = solve(l+1, r, !turn);
  long rv = solve(l, r-1, !turn);

  if(turn){
    memo[l][r] = max(lv + a[l], rv + a[r-1]);
  } else {
    memo[l][r] = min(lv - a[l], rv - a[r-1]);
  }

  visited[l][r] = true;
  return memo[l][r];
}

int main(){
  int n;
  cin>>n;
  rep(i,n) cin>>a[i];

  fill(visited[0], visited[3004], false);

  cout << solve(0,n,true) << endl;

  return 0;
}
