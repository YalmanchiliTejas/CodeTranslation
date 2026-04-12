#include <bits/stdc++.h>
using namespace std;
#define _MACRO(_1, _2, _3, NAME, ...) NAME
#define _repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define _rep(i,n) _repl(i,0,n)
#define rep(...) _MACRO(__VA_ARGS__, _repl, _rep)(__VA_ARGS__)
#define mp make_pair
#define pb push_back
#define all(x) begin(x),end(x)
#define uniq(x) sort(all(x)),(x).erase(unique(all(x)),end(x))
#define fi first
#define se second
#define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
void _dbg(string){cerr<<endl;}
template<class H,class... T> void _dbg(string s,H h,T... t){int l=s.find(',');cerr<<s.substr(0,l)<<" = "<<h<<", ";_dbg(s.substr(l+1),t...);}
template<class T,class U> ostream& operator<<(ostream &o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream &o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

int main(){
  long n,k;
  cin>>n>>k;

  // int a = 0;
  // rep(i,1,n+1) rep(j,1,n+1) if(i%j>=k) a++;
  // dbg(a);

  if(k==0){
    cout << n*n << endl;
    return 0;
  }

  long ans = 0;
  rep(i,k+1,n+1){
    ans += (i-k)*(n/i);
    ans += max(0L, n%i - k + 1);
  }

  cout << ans << endl;

  return 0;
}
