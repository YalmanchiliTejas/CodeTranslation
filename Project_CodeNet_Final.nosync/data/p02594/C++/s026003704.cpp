#include <bits/stdc++.h>
#define trace1(a)                    cout<<#a<<": "<<a<<endl
#define trace2(a,b)                  cout<<#a<<": "<<a<<" | ", trace1(b)
#define trace3(a,b,c)                cout<<#a<<": "<<a<<" | ", trace2(b,c)
#define trace4(a,b,c,d)              cout<<#a<<": "<<a<<" | ", trace3(b,c,d)
#define trace5(a,b,c,d,e)            cout<<#a<<": "<<a<<" | ", trace4(b,c,d,e)
#define trace6(a,b,c,d,e,f)          cout<<#a<<": "<<a<<" | ", trace5(b,c,d,e,f)
#define trace7(a,b,c,d,e,f,g)        cout<<#a<<": "<<a<<" | ", trace6(b,c,d,e,f,g)
#define trace8(a,b,c,d,e,f,g,h)      cout<<#a<<": "<<a<<" | ", trace7(b,c,d,e,f,g,h)
#define trace9(a,b,c,d,e,f,g,h,i)    cout<<#a<<": "<<a<<" | ", trace8(b,c,d,e,f,g,h,i)
#define trace10(a,b,c,d,e,f,g,h,i,j) cout<<#a<<": "<<a<<" | ", trace9(b,c,d,e,f,g,h,i,j)
#define rep(i,a,b)      for(int (i)=(int)(a);(i)<(int)(b); ++(i))
#define reps(i,a,b,c)   for(int (i)=(int)(a);(i)<(int)(b); (i)+=(c))
#define rrep(i,a,b)     for(int (i)=(int)(a);(i)>=(int)(b);--(i))
#define rreps(i,a,b,c)  for(int (i)=(int)(a);(i)>=(int)(b);(i)-=(c))
#define fore(x,a)       for(auto &x:a)
#define foreach(i,a)    for(auto i=(a).begin(); i!=(a).end(); ++i)
#define rforeach(i,a)   for(auto i=(a).rbegin();i!=(a).rend();++i)
#define all(a)  (a).begin(), (a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define isin(i,a,b) ((a) <= (i) && (i) <= (b))
#define uni(a) (a).erase(unique(all(a)),(a).end())
#define dup(x,y) (((x)+(y)-1)/(y))
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define sz(a) ((long long)(a).size())
using namespace std;
struct FastIO { FastIO(){ cin.tie(0); ios::sync_with_stdio(false); cout<<fixed<<setprecision(20); }; } fast_io_;
template <class T> using v  = vector<T>;
template <class T> using vv = v<v<T>>;
template <class T> using upq= priority_queue<T,v<T>,greater<T>>;
template <class T> using dpq= priority_queue<T,v<T>,less<T>>;
using ll  = long long;          using vi  = v<int>;
using ld  = long double;        using vl  = v<ll>;
using unit= unsigned;           using vvi = v<vi>;
using ull = unsigned long long; using vvl = v<vl>;
using pii = pair<int,int>;      using vpii= v<pii>;
using pil = pair<int,ll>;       using vpil= v<pil>;
using pli = pair<ll,int>;       using vpli= v<pli>;
using pll = pair<ll,ll>;        using vpll= v<pll>;
template<class T> ostream& operator<<(ostream&o,const v<T>&v);
template<class T,size_t N> ostream& operator<<(ostream&o,const array<T,N>&v);
template<class T> ostream& operator<<(ostream&o,const deque<T>&v);
template<class T> ostream& operator<<(ostream&o,const queue<T>&v);
template<class T> ostream& operator<<(ostream&o,const set<T>&v);
template<class T> ostream& operator<<(ostream&o,const unordered_set<T>&v);
template<class T> ostream& operator<<(ostream&o,const multiset<T>&v);
template<class T> ostream& operator<<(ostream&o,const unordered_multiset<T>&v);
template<class T,class U> ostream& operator<<(ostream&o,const pair<T,U>&v);
template<class T,class U> ostream& operator<<(ostream&o,const map<T,U>&v);
template<class T,class U> ostream& operator<<(ostream&o,const unordered_map<T,U>&v);
template<class T> ostream& out_with_iter(ostream&o,const T&v){o<<"{"; foreach(x,v)o<<*x<<(next(x)==v.end()?"":","); return o<<"}";}
template<class T> istream& operator>>(istream&i,v<T>&v){fore(x,v)i>>x; return i;}
template<class T> ostream& operator<<(ostream&o,const v<T>&v){return out_with_iter(o,v);}
template<class T,size_t N> ostream& operator<<(ostream&o,const array<T,N>&v){return out_with_iter(o,v);}
template<class T> ostream& operator<<(ostream&o,const deque<T>&v){return out_with_iter(o,v);}
template<class T> ostream& operator<<(ostream&o,const queue<T>&v){queue<T> q(v); o<<"{"; while(sz(q)){o<<q.front()<<(sz(q)==1?"":","); q.pop();} return o<<"}";}
template<class T> ostream& operator<<(ostream&o,const set<T>&v){return out_with_iter(o,v);}
template<class T> ostream& operator<<(ostream&o,const unordered_set<T>&v){return o<<set<T>(all(v)); }
template<class T> ostream& operator<<(ostream&o,const multiset<T>&v){return out_with_iter(o,v);}
template<class T> ostream& operator<<(ostream&o,const unordered_multiset<T>&v){return o<<multiset<T>(all(v));}
template<class T,class U> ostream& operator<<(ostream&o,const pair<T,U>&v){return o<<"("<<v.fi<<","<<v.se<<")";}
template<class T,class U> ostream& operator<<(ostream&o,const map<T,U>&v){o<<"{"; foreach(x,v)o<<x->fi<<"=>"<<x->se<<(next(x)==v.end()?"":","); return o<<"}";}
template<class T,class U> ostream& operator<<(ostream&o,const unordered_map<T,U>&v){return o<<map<T,U>(all(v));}
template<class T> string join(const T&v,char c=' '){stringstream s; foreach(x,v)s<<c<<*x; return sz(s.str())?s.str().substr(1):"";}
template<class T> void YES(T c){if(c) cout<<"YES"<<endl; else cout<<"NO"<<endl;}
template<class T> void Yes(T c){if(c) cout<<"Yes"<<endl; else cout<<"No"<<endl;}
template<class T> void POSS(T c){if(c) cout<<"POSSIBLE"<<endl; else cout<<"IMPOSSIBLE"<<endl;}
template<class T> void Poss(T c){if(c) cout<<"Possible"<<endl; else cout<<"Impossible"<<endl;}
template<class T> bool chmax(T& a,const T& b){ return a<b ? (a=b,true) : false;}
template<class T> bool chmin(T& a,const T& b){ return a>b ? (a=b,true) : false;}
template<class T> T gcd(T a,T b){return b?gcd(b,a%b):a;}
template<class T> T lcm(T a,T b){return a/gcd(a,b)*b;}
constexpr ll TEN(int n){return n==0 ? 1 : 10*TEN(n-1);}
constexpr ld  EPS = 1e-10;
const     ld  PI  = acos(-1.0);
constexpr int INF = 1001002003;
constexpr ll  LINF= 1001002003004005006LL;
constexpr int DX[] = { -1, 0, 1, 0 , -1,-1, 1, 1 };
constexpr int DY[] = {  0, 1, 0,-1 , -1, 1,-1, 1 };

int main() {
  int n;
  cin >> n;
  Yes(n >= 30);
}
