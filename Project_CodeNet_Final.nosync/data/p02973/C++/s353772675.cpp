#include <bits/stdc++.h>
#define REP(i,n) for(int i=0,i##_len=(n);i<i##_len;++i)
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define All(x) (x).begin(),(x).end()
#define rAll(x) (x).rbegin(),(x).rend()
#define ITR(i,x) for(auto i=(x).begin();i!=(x).end();++i)
using namespace std;
using Graph = vector<vector<int>>;

typedef long long ll;
typedef pair<ll, ll> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
constexpr ll mod = 1000000007;

ll mpow(ll x, ll n){ //x^n(mod) ←普通にpow(x,n)では溢れてしまうため，随時mod計算 2分累乗法だから早い
    ll ans = 1;
    while(n != 0){
        if(n&1) ans = ans*x % mod;
        x = x*x % mod;
        n = n >> 1;
    }
    return ans;
}
ll inv_mod(ll a){return mpow(a,mod-2);}
bool square(ll a){ll n=(ll)sqrt(a);return a==n*n;}
int digitsum(ll N,int a){
    if(N==0) return 0;
    int ret=0;
    ret+=digitsum(N/a,a)+N%a;
    return ret;
}
ll gcd(ll x,ll y){return y ? gcd(y,x%y) : x;};//xとyの最大公約数
ll lcm(ll x,ll y){return x/gcd(x,y)*y;}//xとyの最小公倍数
void YN(bool flg){cout<<(flg?"YES":"NO")<<endl;}
void Yn(bool flg){cout<<(flg?"Yes":"No")<<endl;}
void yn(bool flg){cout<<(flg?"yes":"no")<<endl;}
vector<ll> splitint(string n,int a){
    int Len=n.length();
    if(a<0||Len<a) return {-1,-1};
    string left,right;
    if(a!=0) left=n.substr(0,a);
    if(a!=Len) right=n.substr(a);
    return {stoll(left),stoll(right)};
}
class mint {
 private:
  ll _num,_mod;
  mint set(ll num){ 
      _num = num ;
      if(_num>=0) _num%=_mod;
      else _num+=(1-(_num+1)/_mod)*_mod; 
      return *this;
  }
  ll imod(ll n){return mpow(n , _mod-2);}
 public:
  mint(){ _num = 0;_mod=mod; }
  mint(ll num){ _mod = mod; _num = num % mod; }
  mint(ll num,ll M){ _mod=M;set(num); }
  mint(const mint &cp){_num=cp._num;_mod=cp._mod;}
  mint operator= (ll x){ return mint(x % _mod , _mod); }
  mint operator+ (ll x){ return mint(_num + (x % _mod) , _mod); }
  mint operator- (ll x){ return mint(_num - (x % _mod), _mod); }
  mint operator* (ll x){ return mint(_num * (x % _mod) , _mod); }
  mint operator/ (ll x){ return mint(_num * imod(x) , _mod);}
  mint operator+=(ll x){ return set(_num + (x % _mod)); }
  mint operator-=(ll x){ return set(_num - (x % _mod)); }
  mint operator*=(ll x){ return set(_num * (x % _mod)); }
  mint operator/=(ll x){ return set(_num * imod(x));}
  mint operator+ (mint x){ return mint(_num + x._num , _mod); }
  mint operator- (mint x){ return mint(_num - x._num , _mod);}
  mint operator* (mint x){ return mint(_num * x._num , _mod); }
  mint operator/ (mint x){ return mint(_num * imod(x._num) , _mod);}
  mint operator+=(mint x){ return set(_num + x._num); }
  mint operator-=(mint x){ return set(_num - x._num); }
  mint operator*=(mint x){ return set(_num * x._num); }
  mint operator/=(mint x){ return set(_num * imod(x._num));}

  friend mint operator+(ll x,mint m){return mint(m._num + (x % m._mod) , m._mod);}
  friend mint operator-(ll x,mint m){return mint(m._num - (x % m._mod) , m._mod);}
  friend mint operator*(ll x,mint m){return mint(m._num * (x % m._mod) , m._mod);}
  friend mint operator/(ll x,mint m){return mint(m.imod(m._num) * x , m._mod);}

  explicit operator ll() { return _num; }
  explicit operator int() { return _num; }

  friend ostream& operator<<(ostream &os, const mint &x){ os << x._num; return os; }
  friend istream& operator>>(istream &is, mint &x){ll val; is>>val; x.set(val); return is;}
};
class MAT{
 private:
    int row,col;
    vector<vector<double>> _A;
    MAT set(vector<vector<double>> A){_A = A ; return *this;}
    
 public:
    MAT(){ }
    MAT(int n,int m){
        if(n<1 || m<0){cout << "err Matrix::Matrix" <<endl;exit(1);}
        row = n;
        col = m?m:n;//m=0のとき単位行列を作る
        REP(i,row){
            vector<double> a(col);
            _A.push_back(a);
            REP(j,col) _A[i][j]=0;
        }
        //  値の初期化
        if(m==0) REP(i,n) _A[i][i]=1.0;
    }
    MAT(const MAT &cp){_A=cp._A;row=cp.row;col=cp.col;}
    double* operator[] (int i){return _A[i].data();}
    MAT operator= (vector<vector<double>> x) {return set(x);}
    MAT operator+ (MAT x) {
        if(row!=x.row || col!=x.col){
            cout << "err Matrix::operator+" <<endl;
            cout << "  not equal matrix size" <<endl;
            exit(0);
        }
        MAT r(row, col);
        REP(i,row) REP(j,col) r[i][j]=_A[i][j]+x[i][j];
        return r;
    }
    MAT operator- (MAT x) {
        if(row!=x.row || col!=x.col){
            cout << "err Matrix::operator-" <<endl;
            cout << "  not equal matrix size" <<endl;
            exit(0);
        }
        MAT r(row, col);
        REP(i,row) REP(j,col) r[i][j]=_A[i][j]-x[i][j];
        return r;
    }
    MAT operator* (MAT x) {
        if(col!=x.row){
            cout << "err Matrix::operator*" <<endl;
            cout << "  not equal matrix size" <<endl;
            exit(0);
        }
        MAT r(row, x.col);
        REP(i,row) REP(j,x.col) REP(k,col) r[i][j]+=_A[i][k]*x[k][j];
        return r;
    }
    MAT operator/ (double a){
        MAT r(row,col);
        REP(i,row) REP(j,col) r[i][j]=_A[i][j]/a;
        return r;
    }
    MAT operator^ (ll n){
        if(row!=col){
            cout << "err Matrix::operator^" <<endl;
            cout << "  not equal matrix size" <<endl;
            exit(0);
        }
        MAT r(row,0),A=*this;
        while(n){
            if(n&1) r *= A;
            A*=A;
            n>>=1;
        }
        return r;
    }
    MAT operator+= (MAT x) {
        if(row!=x.row || col!=x.col){
            cout << "err Matrix::operator+=" <<endl;
            cout << "  not equal matrix size" <<endl;
            exit(0);
        }
        MAT r(row, col);
        REP(i,row) REP(j,col) r[i][j]=_A[i][j]+x[i][j];
        return set(r._A);
    }
    MAT operator-= (MAT x) {
        if(row!=x.row || col!=x.col){
            cout << "err Matrix::operator-=" <<endl;
            cout << "  not equal matrix size" <<endl;
            exit(0);
        }
        MAT r(row, col);
        REP(i,row) REP(j,col) r[i][j]=_A[i][j]-x[i][j];
        return set(r._A);
    }
    MAT operator*= (MAT x) {
        if(col!=x.row){
            cout << "err Matrix::operator*" <<endl;
            cout << "  not equal matrix size" <<endl;
            exit(0);
        }
        MAT r(row, x.col);
        REP(i,row) REP(j,x.col) REP(k,col) r[i][j]+=_A[i][k]*x[k][j];
        return set(r._A);
    }
    MAT operator/=(double a){
        MAT r(row,col);
        REP(i,row) REP(j,col) r[i][j]=_A[i][j]/a;
        return r;
    }

    friend MAT operator* (double n,MAT x){
        MAT r(x.row,x.col);
        REP(i,x.row) REP(j,x.col) r[i][j]=n*x[i][j];
        return r;
    }
    friend MAT operator* (MAT x,double n){
        MAT r(x.row,x.col);
        REP(i,x.row) REP(j,x.col) r[i][j]=n*x[i][j];
        return r;
    }
    explicit operator vector<vector<double>>(){return _A;}
    friend ostream &operator<<(ostream &os,const MAT &x){ REP(i,x.row) REP(j,x.col) os<<x._A[i][j]<<" \n"[j==x.col-1]; return os;}
    
    int size_row(){return row;}
    int size_col(){return col;}
    MAT transpose(){
        MAT r(col,row);
        REP(i,col) REP(j,row) r[i][j]=_A[j][i];
        return r;
    }
};
class UnionFind{//UnionFind木
 private:
    vector<int> Parent;
 public:
    UnionFind(int N){
        Parent.resize(N);
        REP(i,N) Parent[i]=-1;
    }

    int root(int A){
        if(Parent[A]<0) return A;
        else return Parent[A]=root(Parent[A]);
    }

    int size(int A){
        return -Parent[root(A)];
    }

    bool connect(int A,int B){
        A=root(A); B=root(B);
        if(A==B) return false;
        if(size(A)<size(B)) swap(A,B);
        Parent[A]+=Parent[B];
        Parent[B]=A;
        return true;
    }
};
class Factorial{//階乗とその逆元を求めて計算に利用するクラス
 private:
    vector<ll> fac;
    vector<ll> ifac;
 public:
    
    Factorial(ll N){
        fac.push_back(1);
        REP(i,N) fac.push_back(fac[i]*(i+1)%mod);
        ifac.resize(N+1);
        ifac[N]=inv_mod(fac[N]);
        REP(i,N) ifac[N-1-i]=(ifac[N-i]*(N-i))%mod;
    }

    ll fact(ll a){return fac[a];}
    ll ifact(ll a){return ifac[a];}

    ll cmb(ll a,ll b){
        if(a==0&&b==0) return 1;
        if(a<b||a<0||b<0) return 0;
        ll tmp =ifact(a-b)*ifact(b)%mod;
        return tmp*fac[a]%mod;
    }
    ll per(ll a,ll b){
        if(a==0&&b==0) return 1;
        if(a<b||a<0||b<0) return 0;
        return fac[a]*ifac[a-b]%mod;
    }
};
class SOSU{
 private:
    vector<ll> Prime_Number;
 public:
    SOSU(int N){
        set<ll> arr;
        REP(i,N-1)  arr.insert(i+2);
        while(int n=*arr.begin()){
            if(n>sqrt(N)) break;
            Prime_Number.push_back(n);
            rep(i,1,N/n+1) arr.erase(n*i);
        }
        ITR(itr,arr) Prime_Number.push_back(*itr);
    }
    ll operator[](int i){return Prime_Number[i];}
    int count(){return Prime_Number.size();}
    bool isPrime(int q){return binary_search(All(Prime_Number),q);}
};
struct Solutions{
    ll napsack(int kinds,int MAX_W,const vl weight,const vl cost){
        vector<vector<ll>> dp(kinds+1,vector<ll>(MAX_W+1,0));
        REP(i,kinds) REP(j,MAX_W+1){
            if(j<weight[i]) dp[i+1][j]=dp[i][j];
            else dp[i+1][j]=max(dp[i][j],dp[i][j-weight[i]]+cost[i]);
        }
        return dp[kinds][MAX_W];
    }
    ll unlimited_napsack(int kinds,int MAX_W,const vl weight,const vl cost){
        vector<vector<ll>> dp(kinds+1,vector<ll>(MAX_W+1,0));
        REP(i,kinds) REP(j,MAX_W+1){
            if(j<weight[i]) dp[i+1][j]=dp[i][j];
            else dp[i+1][j]=max(dp[i][j],dp[i+1][j-weight[i]]+cost[i]);
        }
        return dp[kinds][MAX_W];
    }
    ll Partition_Func(int n,int k){
        vector<vector<ll>> dp(k+1,vector<ll> (n+1,0));
        dp[0][0]=1;
        rep(i,1,k+1) REP(j,n+1){
            if(j-i>=0) dp[i][j]=(dp[i][j-i]+dp[i-1][j]);
            else dp[i][j]=dp[i-1][j];
        }
        return dp[k][n];
    }
    int LCS(string s,string t){
        int n=s.length(),m=s.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1));
        REP(i,n) REP(j,m){
            if (s[i] == t[j]) dp[i+1][j+1] = dp[i][j] + 1;
            else dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
        }
        return dp[n][m];
    }
    int LIS(const vector<ll> a){
        int n=a.size();
        ll INF=1<<28;
        vector<ll> dp(n+1,INF);
        REP(i,n) *lower_bound(All(dp),a[i])=a[i];
        int k=lower_bound(All(dp),INF)-dp.begin();
        return k;
    }
};
struct edge{
    int from;int to;ll cost;
    void push(int a,int b,int c){
        from=a;to=b;cost=c;
    }
    bool operator<(const edge& y) const{
        if(cost!=y.cost) return cost<y.cost;
        else if(to!=y.to) return to<y.to;
        else return from<y.from;}
    bool operator>(const edge& y) const{
        if(cost!=y.cost) return cost>y.cost;
        else if(to!=y.to) return to>y.to;
        else return from>y.from;}
    bool operator==(const edge& y) const{return *this==y;}
};
class lca {
  public:
    const int n = 0;
    const int log2_n = 0;
    std::vector<std::vector<int>> parent;
    std::vector<int> depth;

    lca() {}

    lca(const Graph &g, int root)
        : n(g.size()), log2_n(log2(n) + 1), parent(log2_n, std::vector<int>(n)), depth(n) {
        dfs(g, root, -1, 0);
        for (int k = 0; k + 1 < log2_n; k++) {
            for (int v = 0; v < (int)g.size(); v++) {
                if (parent[k][v] < 0)
                    parent[k + 1][v] = -1;
                else
                    parent[k + 1][v] = parent[k][parent[k][v]];
            }
        }
    }

    void dfs(const Graph &g, int v, int p, int d) {
        parent[0][v] = p;
        depth[v] = d;
        REP(j,g[v].size()) {
            if (g[v][j] != p) dfs(g, g[v][j], v, d + 1);
        }
    }

    int get(int u, int v) {
        if (depth[u] > depth[v]) std::swap(u, v);
        for (int k = 0; k < log2_n; k++) {
            if ((depth[v] - depth[u]) >> k & 1) {
                v = parent[k][v];
            }
        }
        if (u == v) return u;
        for (int k = log2_n - 1; k >= 0; k--) {
            if (parent[k][u] != parent[k][v]) {
                u = parent[k][u];
                v = parent[k][v];
            }
        }
        return parent[0][u];
    }
};
template <typename T,typename E> 
struct SegmentTree{
  typedef function<T(T,T)> F;
  typedef function<T(T,E)> G;
  int n;
  F f;
  G g;
  T d1;
  E d0;
  vector<T> dat;
  SegmentTree(){};
  SegmentTree(int n_,F f,G g,T d1,
	      vector<T> v=vector<T>()):
    f(f),g(g),d1(d1){
    init(n_);
    if(n_==(int)v.size()) build(n_,v);
  }
  void init(int n_){
    n=1;
    while(n<n_) n*=2;
    dat.clear();
    dat.resize(2*n-1,d1);
  }
  void build(int n_, vector<T> v){
    for(int i=0;i<n_;i++) dat[i+n-1]=v[i];
    for(int i=n-2;i>=0;i--)
      dat[i]=f(dat[i*2+1],dat[i*2+2]);
  }
  void update(int k,E a){
    k+=n-1;
    dat[k]=g(dat[k],a);
    while(k>0){
      k=(k-1)/2;
      dat[k]=f(dat[k*2+1],dat[k*2+2]);
    }
  }
  inline T query(int a,int b){
    T vl=d1,vr=d1;
    for(int l=a+n,r=b+n;l<r;l>>=1,r>>=1) {
      if(l&1) vl=f(vl,dat[(l++)-1]);
      if(r&1) vr=f(dat[(--r)-1],vr);
    }
    return f(vl,vr);
  }
  
};


int main(){
    int N;
    cin>>N;
    vector<int> A(N);
    REP(i, N) cin >> A[i];
    deque<P> color;
    color.push_front(P(A[0]+1,0));
    REP(i,N-1){
        auto k=upper_bound(All(color),P(A[i+1],0))-color.begin();
        if(A[i]<A[i+1]){ //A[i+1]が前の色の最低値以上ならそっちを更新する
            if(k==0) color.front().first=A[i+1]+1;
            else color[k-1].first=A[i+1]+1;
        }
        else{
            //cout<<k<<endl;
            if(k==color.size()) color.back().first=A[i+1]+1;
            else if(k==0)color.push_front(P(A[i+1]+1,k));
            else color[k-1].first=A[i+1]+1;
        }
    }
    cout<<color.size()<<endl;
}