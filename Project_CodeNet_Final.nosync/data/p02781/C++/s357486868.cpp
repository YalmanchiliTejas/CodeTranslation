#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define uni(x) x.erase(unique(rng(x)),x.end())
#define PQ(T) priority_queue<T,v(T),greater<T> >
#define dup(x,y) (((x)+(y)-1)/(y))
#define v(T) vector<T>
#define vv(T) v(v(T))
using ll = int64_t;
using ull = uint64_t;
using uint = uint32_t;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using pil = pair<int,ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
template<typename T>inline istream& operator>>(istream&i,v(T)&v)
{rep(j,v.size())i>>v[j];return i;}
template<typename T>string join(const v(T)&v)
{stringstream s;rep(i,v.size())s<<' '<<v[i];return s.str().substr(1);}
template<typename T>inline ostream& operator<<(ostream&o,const v(T)&v)
{if(v.size())o<<join(v);return o;}
template<typename T1,typename T2>inline istream& operator>>(istream&i,pair<T1,T2>&v)
{return i>>v.fi>>v.se;}
template<typename T1,typename T2>inline ostream& operator<<(ostream&o,const pair<T1,T2>&v)
{return o<<v.fi<<","<<v.se;}
const double eps = 1e-6;
const ll LINF = 100200300400500600ll;
const int INF = 1001001001;
//--------------------------------------------------------
#define fastio cin.tie(nullptr); std::ios::sync_with_stdio(false);
#define myio ifstream iofi; if(argc>1){iofi.open(argv[1]); std::cin.rdbuf(iofi.rdbuf());}
#define myloopset int loop = 1; if(argc>2) loop =stoi(argv[2]); rep(i,loop)
//--------------------------------------------------------------
template <class T> T chmin(T &a,T b){if(a>b){a=b; return 1;}else return 0;}
template <class T> T chmax(T &a,T b){if(a<b){a=b; return 1;}else return 0;}
const int dx[4] = {0,1,0,-1};
const int dy[4] = {-1,0,1,0};
#define MOD 1000000007

ll binomial(int N, int K) {
  if(K < 0 || N < K) return 0;
  ll ret = 1;
  for(ll i = 1; i <= K; ++i) {
    ret *= N--;
    ret /= i;
  }
  return ret;
}
void Main(){
  string s;
  cin>>s;
  int k;
  cin>>k;
  if(s.length()>=k){
    ll ans = binomial(s.length(),k);
    rep(i,k) ans*=9;
    if(k==1){
      string t(s.length(),'0');
      srep(i,1,10){
        t[0] = i+'0';
        if(s<t) ans--;
      }
    }else if(k==2){
      srep(i,1,10){
        srep(j,1,10){
          rep(k,s.length()-1){
            string t(s.length(),'0');
            t[0] = i+'0';
            t[k+1] = j+'0'; 
            if(s<t) ans--;
          }
        }
      }
    } else {
      srep(i,1,10){
        srep(j,1,10){
          srep(k,1,10){
            srep(p1,1,s.length()){
              srep(p2,p1+1,s.length()){
                string t(s.length(),'0');
                t[0] = i+'0';
                t[p1] = j+'0'; 
                t[p2] = k+'0'; 
                if(s<t) ans--;
              }
            }
          }
        }
      }
    }

    cout<<ans<<endl;
  }else{
    cout<<0<<endl;
    return;
  }


} signed main(int argc,char** argv)
{fastio; myio; myloopset Main();}
