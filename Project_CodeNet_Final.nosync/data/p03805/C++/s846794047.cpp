#include <bits/stdc++.h>
using namespace std;

#define _p(...) (void)printf(__VA_ARGS__)
#define forr(x,arr) for(auto&& x:arr)
#define _overload3(_1,_2,_3,name,...) name
#define _rep2(i,n) _rep3(i,0,n)
#define _rep3(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,_rep3,_rep2,)(__VA_ARGS__)
#define _rrep2(i,n) _rrep3(i,0,n)
#define _rrep3(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define rrep(...) _overload3(__VA_ARGS__,_rrep3,_rrep2,)(__VA_ARGS__)
#define all(x) (x).begin(), (x).end()
#define bit(n) (1LL<<(n))
#define sz(x) ((int)(x).size())
#define fst first
#define snd second
using ll=long long;
using pii=pair<int,int>;using pll=pair<ll,ll>;using pil=pair<int,ll>;using pli=pair<ll,int>;
using vs=vector<string>;using vvs=vector<vs>;using vvvs=vector<vvs>;
using vb=vector<bool>;using vvb=vector<vb>;using vvvb=vector<vvb>;
using vi=vector<int>;using vvi=vector<vi>;using vvvi=vector<vvi>;
using vl=vector<ll>;using vvl=vector<vl>;using vvvl=vector<vvl>;
using vd=vector<double>;using vvd=vector<vd>;using vvvd=vector<vvd>;
using vpii=vector<pii>;using vvpii=vector<vpii>;using vvvpii=vector<vvpii>;
template<class T,class U>istream&operator>>(istream&is,pair<T,U>&P){is>>P.fst;is>>P.snd;return is;}
template<class T>T read(){T t;cin>>t;return t;}
template<class T,class U>ostream&operator<<(ostream&o,const pair<T,U>&p){return o<<'('<<p.fst<<", "<<p.snd<<')';}
template<class T>ostream&operator<<(ostream&o,const vector<T>&t){o<<"{";rep(i,sz(t))o<<t[i]<<",";o<<"}"<<endl;return o;}
vs s_p_l_i_t(const string&s,char c){vs v;stringstream ss(s);string x;while(getline(ss,x,c))v.emplace_back(x);return move(v);}
void e_r_r(vs::iterator it){cerr<<endl;}
template<class T,class... Args>void e_r_r(vs::iterator it,T a,Args... args){cerr<<it->substr((*it)[0]==' ',it->length())<<" = "<<a<<", ";e_r_r(++it,args...);}
#define out(args...){vs a_r_g_s=s_p_l_i_t(#args,',');e_r_r(a_r_g_s.begin(),args);}

void Main() {
  int n = read<int>();
  int m = read<int>();
  vvi E(n);
  rep(i, m) {
    int u = read<int>() - 1;
    int v = read<int>() - 1;
    E[u].push_back(v);
    E[v].push_back(u);
  }

  int ans = 0;

  function<void(int, int)> dfs = [&](int cur, int vis) {
    vis |= bit(cur);

    if (__builtin_popcount(vis) == n) ans++;

    forr(nex, E[cur]) {
      if ((bit(nex) & vis) == 0) {
        dfs(nex, vis);
      }
    }
  };
  dfs(0, 0);
  cout << ans << endl;
}
int main() { cin.tie(nullptr); ios::sync_with_stdio(false); Main(); return 0; }
