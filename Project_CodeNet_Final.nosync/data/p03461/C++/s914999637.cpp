#include <bits/stdc++.h>
using namespace std;
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define _repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define _rep(i,n) _repl(i,0,n)
#define rep(...) GET_MACRO(__VA_ARGS__, _repl, _rep)(__VA_ARGS__)
#define mp(a,b) make_pair((a),(b))
#define pb(a) push_back((a))
#define all(x) (x).begin(),(x).end()
#define uniq(x) sort(all(x)),(x).erase(unique(all(x)),end(x))
#define fi first
#define se second
#define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
void _dbg(string){cout<<endl;}
template<class H,class... T> void _dbg(string s,H h,T... t){int l=s.find(',');cout<<s.substr(0,l)<<" = "<<h<<", ";_dbg(s.substr(l+1),t...);}
template<class T,class U> ostream& operator<<(ostream &o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream &o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

#define INF 1120000000

int d[11][11];
int w[102][102];

int main(){
  int a,b;
  cin>>a>>b;
  rep(i,a) rep(j,b) cin>>d[i][j];

  rep(i,101) rep(j,101){
    // i*x + j*y + w[i][j] >= d[k][l] for all k,l
    w[i][j] = 0;
    rep(k,a) rep(l,b) w[i][j] = max(w[i][j], d[k][l] - i*(k+1) - j*(l+1));
  }

  rep(k,a) rep(l,b){
    int tmp = INF;
    rep(i,101) rep(j,101){
      tmp = min(tmp, w[i][j] + i*(k+1) + j*(l+1));
    }
    if(tmp != d[k][l]){
      cout << "Impossible" << endl;
      return 0;
    }
  }

  cout << "Possible\n";
  cout << "202 10401\n";

  rep(i,1,101) cout << i << " " << i+1 << " X\n";
  rep(i,102,202) cout << i << " " << i+1 << " Y\n";
  rep(i,101) rep(j,101){
    cout << i+1 << " " << 202-j << " " << w[i][j] << "\n";
  }

  cout << "1 202\n";

  return 0;
}
