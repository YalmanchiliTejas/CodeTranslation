#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define rrep(i,n) for(int i=1,i##_len=(n); i<=i##_len; ++i)
#define drep(i,n) for(int i=(n)-1; i>=0; --i)
#define srep(i,s,t) for(int i=(s);i<(t);++i)
#define rng(obj) (obj).begin(), (obj).end()
#define maxs(x,y) (x=max((x),(y)))
#define mins(x,y) (x=min((x),(y)))
#define limit(x,l,r) max(l,min(x,r))
#define lims(x,l,r) (x=max(l,min(x,r)))
#define isin(x,l,r) ((l) <= (x) && (x) < (r))
#define pb push_back
#define sz(x) (int)(x).size()
#define uni(x) x.erase(unique(rng(x)),x.end())
#define show(x) cout<<#x<<" = "<<x<<endl;
#define PQ(T) priority_queue<T,v(T),greater<T>>
#define bn(x) ((1<<x)-1)
#define dup(x,y) (((x)+(y)-1)/(y))
#define newline puts("")
#define v(T) vector<T>
#define vv(T) vector<vector<T>>
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vp = vector<P>;
template <class T> inline istream& operator>>(istream&i,v(T)&v)
{ rep(j,sz(v))i>>v[j];return i;}
template <class T> string join(const v(T)&v)
{ stringstream s;rep(i,sz(v))s<<' '<<v[i];return s.str().substr(1);}
template <class T> inline ostream& operator<<(ostream&o,const v(T)&v)
{ if(sz(v))o<<join(v); return o;}
template <class T1,class T2> inline istream& operator>>(istream&i ,pair<T1,T2>&v)
{ return i>>v.fi>>v.se;}
template <class T1,class T2> inline ostream& operator<<(ostream&o ,pair<T1,T2>&v)
{ return o<<v.fi<<","<<v.se;}
template <class T> inline ll suma(const v(T)& a) 
{ ll res(0); for(auto&& x:a) res += x; return res;}
const int INF = 1001001001;
const ll LINF = 1001002003004005006ll;
const double eps = 1e-10;
const int MX = 200005;
//----------------------------------------------------------------

#define fileio ifstream fio; if(argc>=2){fio.open(argv[1]); std::cin.rdbuf(fio.rdbuf());}
#define fastio ios_base::sync_with_stdio(false);
#define MOD 1000000007
//----------------------------------------------------------------
void Main(){
  int n;
  cin>>n;
  vl x(n);
  cin>>x;
  vl w = x;
  sort(rng(w));
  int hn = n/2;
  rep(i,n){
    if( distance(w.begin(), upper_bound(rng(w),x[i]-1)) < hn ){
      cout<<w[hn]<<endl;
    }else{
      cout<<w[hn-1]<<endl;
    }
  }

} int main(int argc,char* argv[]){ 
    fastio; fileio; Main();}