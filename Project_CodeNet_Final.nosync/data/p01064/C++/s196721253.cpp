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

#define long long long // for codeforces

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n;
  long a,d;
  int m;
  cin>>n>>a>>d>>m;

  vector<int> x(m), y(m), z(m);
  rep(i,m) cin>>x[i]>>y[i]>>z[i];
  rep(i,m) y[i]--,z[i]--;
  int k;
  cin>>k;
  k--;

  for(int i=m-1; i>=0; i--){
    if(x[i]==0 && y[i]<=k && k<=z[i]){
      k = y[i] + z[i] - k;
    }
  }

  long ans = a + d*k;
  rep(i,m) if(y[i]<=k && k<=z[i]){
    if(x[i]==0){
      k = y[i] + z[i] - k;
    }
    else if(x[i]==1){
      ans++;
    }
    else if(x[i]==2){
      ans /= 2;
    }
    else assert(false);
  }

  cout << ans << endl;

  return 0;
}

