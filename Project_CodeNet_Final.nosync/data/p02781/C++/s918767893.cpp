#include <bits/stdc++.h>
#define trace1(a)               cout<<#a<<": "<<a<<endl
#define trace2(a,b)             cout<<#a<<": "<<a<<" | ", trace1(b)
#define trace3(a,b,c)           cout<<#a<<": "<<a<<" | ", trace2(b,c)
#define trace4(a,b,c,d)         cout<<#a<<": "<<a<<" | ", trace3(b,c,d)
#define trace5(a,b,c,d,e)       cout<<#a<<": "<<a<<" | ", trace4(b,c,d,e)
#define trace6(a,b,c,d,e,f)     cout<<#a<<": "<<a<<" | ", trace5(b,c,d,e,f)
#define trace7(a,b,c,d,e,f,g)   cout<<#a<<": "<<a<<" | ", trace6(b,c,d,e,f,g)
#define trace8(a,b,c,d,e,f,g,h) cout<<#a<<": "<<a<<" | ", trace7(b,c,d,e,f,g,h)
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rrep(i,a,b) for(int i=(int)(a);i>=(int)(b);--i)
#define fore(x,a) for(auto &x:a)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define isin(i,a,b) ((a) <= (i) && (i) <= (b))
#define uni(a) (a).erase(unique(all(a)),(a).end())
#define dup(x,y) (((x)+(y)-1)/(y))
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define sz(a) ((long long)(a).size())
#define v(T) vector<T>
#define vv(T) v(v(T))
using namespace std;
using ll  = long long;          using vi  = vector<int>;
using unit= unsigned;           using vl  = vector<ll>;
using ull = unsigned long long; using vvi = vector<vi>;
using pii = pair<int,int>;      using vvl = vector<vl>;
using pll = pair<ll,ll>;        using vp  = vector<pii>;
void _main(); int main(){ cin.tie(0); ios::sync_with_stdio(false); _main(); }
template<class T>string join(const v(T)&v){ stringstream s; rep(i,0,sz(v))s<<' '<<v[i]; return s.str().substr(1); }
template<class T>istream &operator>>(istream&i, v(T)&v){ fore(x,v){ i >> v; } return i; }
template<class T>ostream &operator<<(ostream&o, const v(T)&v){ o<<"["; fore(x,v)o<<x<<","; o<<"]"; return o; }
template<class T>ostream &operator<<(ostream&o, const deque<T>&v){ o<<"deq["; fore(x,v)o<<x<<","; o<<"]"; return o; }
template<class T>ostream &operator<<(ostream&o, const set<T>&v){ o<<"{"; fore(x,v)o<<x<<","; o<<"}"; return o; }
template<class T>ostream &operator<<(ostream&o, const unordered_set<T>&v){ o<<"{"; fore(x,v)o<<x<<","; o<<"}"; return o; }
template<class T>ostream &operator<<(ostream&o, const multiset<T>&v){ o<<"{"; fore(x,v)o<<x<<","; o<<"}"; return o; }
template<class T>ostream &operator<<(ostream&o, const unordered_multiset<T>&v){ o<<"{"; fore(x,v)o<<x<<","; o<<"}"; return o; }
template<class T1,class T2>ostream &operator<<(ostream &o, const pair<T1,T2>&p){ o<<"("<<p.fi<<","<<p.se<<")"; return o; }
template<class TK,class TV>ostream &operator<<(ostream &o, const map<TK,TV>&m){ o<<"{"; fore(x,m)o<<x.fi<<"=>"<<x.se<<","; o<<"}"; return o; }
template<class TK,class TV>ostream &operator<<(ostream &o, const unordered_map<TK,TV>&m){ o<<"{"; fore(x,m)o<<x.fi<<"=>"<<x.se<<","; o<<"}"; return o; }
template<class T>void YES(T c){ if(c) cout<<"YES"<<endl; else cout<<"NO"<<endl; }
template<class T>void Yes(T c){ if(c) cout<<"Yes"<< endl; else cout<<"No"<<endl; }
template<class T>void POSS(T c){ if(c) cout<<"POSSIBLE"<<endl; else cout<<"IMPOSSIBLE"<<endl; }
template<class T>void Poss(T c){ if(c) cout<<"Possible"<<endl; else cout<<"Impossible"<<endl; }
template<class T>void chmax(T &a, const T &b){ if(a<b) a=b; }
template<class T>void chmin(T &a, const T &b){ if(b<a) a=b; }
template<class T>T gcd(T a, T b){ return b?gcd(b,a%b):a; }
template<class T>T lcm(T a, T b){ return a/gcd(a,b)*b; }
const double  EPS = 1e-10;
const double  PI  = acos(-1.0);
const int     INF = 1001002003;
const ll      LINF= 1001002003004005006LL;
const int dx[] = { -1, 0, 1, 0 , -1,-1, 1, 1 };
const int dy[] = {  0, 1, 0,-1 , -1, 1,-1, 1 };

int dp[105][2][4];

void _main() {
  string s;
  int K;
  cin >> s >> K;
  int n = sz(s);
  dp[0][0][0] = 1;
  rep(i,0,n)rep(j,0,2)rep(k,0,4) {
    int nd = s[i]-'0';
    rep(d,0,10) {
      int ni = i+1, nj = j, nk = k;
      if (d != 0) ++nk;
      if (nk > K) continue;
      if (j == 0) {
        if (d > nd) continue;
        if (d < nd) nj = 1;
      }
      dp[ni][nj][nk] += dp[i][j][k];
    }
  }
  int ans = dp[n][0][K] + dp[n][1][K];
  cout << ans << endl;
}