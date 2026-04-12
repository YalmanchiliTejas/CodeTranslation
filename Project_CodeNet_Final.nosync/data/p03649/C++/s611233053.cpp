#include <bits/stdc++.h> // ver2.7.0
#define int long long
#define endl "\n" // fflush(stdout);
#define ALL(v) (v).begin(),(v).end()
#define Vi vector<int>
#define VVi vector<Vi>
#define VVVi vector<VVi>
#define Vm vector<mint>
#define Vs vector<string>
#define Vd vector<double>
#define Vc vector<char>
#define Pii pair<int,int>
#define Pdd pair<double,double>
#define VPii vector<Pii>
#define Tiii tuple<int,int,int>
#define VTiii vector<Tiii>
#define PQi priority_queue<int>
#define PQir priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define itos to_string
#define stoi stoll
#define FI first
#define SE second
#define cYES cout<<"YES"<<endl
#define cNO cout<<"NO"<<endl
#define cYes cout<<"Yes"<<endl
#define cNo cout<<"No"<<endl
#define cyes cout<<"yes"<<endl
#define cno cout<<"no"<<endl
#define sortr(v) sort(v,greater<>())
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repeq(i,a,b) for(int i=a;i<=b;i++)
#define repreq(i,a,b) for(int i=a;i>=b;i--)
#define dem(a,b) ((a+b-1)/(b))
#define INF 3000000000000000000 // 3.0*10^18
#define MAX LLONG_MAX
#define PI acos(-1.0L)
//int MOD = 998244353; // case
const int MOD = 1000000007; // 10^9 + 7
const double EPS = 1e-10;

using namespace std;

struct mint{int x;mint(int x=0):x((x%MOD+MOD)%MOD){}
mint operator-()const{return mint(-x);}
mint& operator+=(const mint a){if((x+=a.x)>=MOD)x-=MOD;return*this;}
mint& operator-=(const mint a){if((x+=MOD-a.x)>=MOD)x-=MOD;return*this;}
mint& operator*=(const mint a){(x*=a.x)%=MOD;return*this;}
mint operator+(const mint a)const{return mint(*this)+=a;}
mint operator-(const mint a)const{return mint(*this)-=a;}
mint operator*(const mint a)const{return mint(*this)*=a;}
mint pow(int t)const{if(!t)return 1;mint a=pow(t>>1);a*=a;if(t&1)a*=*this;return a;}
mint inv()const{return pow(MOD-2);}
mint& operator/=(const mint a){return*this*=a.inv();}
mint operator/(const mint a)const{return mint(*this)/=a;}};
istream& operator>>(istream& is, const mint& a) {return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) {return os << a.x;}

/* debug */
template <typename T> // vector
ostream& operator<<(ostream& os,const vector<T> &V){int N=V.size();
if(N==0){os<<'.';return os;}rep(i,0,N-1){os<<V[i]<<' ';}os<<V[N-1];return os;}
template <typename T> // vector vector
ostream& operator<<(ostream& os,const vector<vector<T>> &V){
int N=V.size();rep(i,0,N-1)cout<<V[i]<<endl;cout<<V[N-1];return os;}
template <typename T,typename S> // pair
ostream& operator<<(ostream& os, pair<T,S> const&P){os<<P.FI<<' '<<P.SE;return os;}
template <typename T> // set
ostream& operator<<(ostream& os,set<T> &S){auto it=S.begin();while(it!=S.end()){
os<<*it;if(next(it,1)!=S.end())os<<' ';it++;};return os;}
template <typename T> // deque
ostream& operator<<(ostream& os, deque<T> &q){for(auto it=q.begin();it<q.end();it++){
os<<*it;if(it+1!=q.end())os<<" ";}return os;}

/* useful */
void Vin(auto &v){int n=v.size();rep(i,0,n)cin>>v[i];}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int lcm(int a,int b){return a/gcd(a,b)*b;}
int mypow(int x, int n, int m){
if(n==0)return 1;if(n%2==0)return mypow(x*x%m,n/2,m);else return x*mypow(x,n-1,m)%m;}
int scomb(int n, int r){if(r<0||r>n)return 0;if((n-r)<r)r=n-r; // nCr
int a=1;for(int i=n;i>n-r;--i){a=a*i;}for(int i=1;i<r+1;++i){a=a/i;}return a;}
Vi vis(Vi &v){Vi S(v.size()+1);rep(i,1,S.size())S[i]+=v[i-1]+S[i-1];return S;}
int digit(int k,int i){string s = itos(k);return s[s.size()-i]-'0';} // i桁目の数字
void press(auto &v){v.erase(unique(ALL(v)),v.end());} // 圧縮
Vi zip(Vi b){int Z=b.size(); // 座標圧縮
Pii p[Z+10];int a=b.size();Vi l(a);for(int i=0;i<a;i++)
p[i]=mp(b[i],i);sort(p,p+a);int w=0;for(int i=0;i<a;i++)
{if(i&&p[i].first!=p[i-1].first)w++;l[p[i].second]=w;}return l;}
Vi nibe2V(){Vi a(63);int q = 1;rep(i,0,63){a[i]=q;q*=2;}return a;}
Vi nibe = nibe2V(); // 2^n
int modiv(int a,int b){return a*mypow(b,MOD-2,MOD)%MOD;} // a÷b(%MOD)
int SMALLER(Vi &a,int x){return lower_bound(a.begin(),a.end(),x)-a.begin();}
int orSMALLER(Vi &a,int x){return upper_bound(a.begin(),a.end(),x)-a.begin();}
int BIGGER(Vi &a,int x){return a.size()-orSMALLER(a,x);}
int orBIGGER(Vi &a,int x){return a.size()-SMALLER(a,x);}
int COUNT(Vi &a,int x) {return upper_bound(ALL(a),x)-lower_bound(ALL(a),x);}
int maxind(Vi &a){return max_element(ALL(a))-a.begin();}
int minind(Vi &a){return min_element(ALL(a))-a.begin();}
Vi stpowV(){Vi a(300005);a[0]=1;repeq(i,1,300004)a[i]=a[i-1]*i%MOD;return a;}
//Vi stpow = stpowV(); // 階乗配列(%MOD)

/****************************** START ******************************/

signed main() {
  cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);cout<<fixed<<setprecision(12);
  int n;
  cin >> n;
  Vi a(n);
  Vin(a);
  
  int sum = 0;
  rep(i,0,n){
    sum += a[i];
  }
  
  int ans = 0;
  
  int maxx = (n-1)*n;
  int re = sum - maxx;
  cerr << "# " << re << endl;
  
  if(maxx < sum){
    ans += re;
    rep(i,0,n){
      a[i] += re;
    }
    sortr(ALL(a));
    
    rep(i,0,n){
      int mi;
      mi = dem(a[i],n+1);
      mi--;
      if(a[i]%(n+1) == 0|| a[i]%(n+1) == n) mi++;
      
      a[i] -= (n+1)*min(re,mi);
      re -= mi;
      if(re < 0) re = 0;
    }
    
  }
  
  sortr(ALL(a));
  cerr << a << endl;
  cerr << ans << endl;
  
  while(a[0] >= n){
    ans++;
    a[0] -= n;
    rep(i,1,n) a[i]++;
    sortr(ALL(a));
  }
  
  cout << ans << endl;
  return 0;
}