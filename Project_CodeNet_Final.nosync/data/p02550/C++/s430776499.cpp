// #Sazaの1日1AC
#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
const long long INF=9e18;
const double PI=3.14159265358979323846;

//マクロ
//型エイリアス
using ll = long long;
using P=pair<long long, long long>;
using vl=vector<long long>;
using vvl=vector<vector<long long>>;
using vP=vector<pair<long long, long long>>;
//ショートカット
#define rep(i,n) for(long long i = 0; i < n; i++)
#define rep2(i,k,n) for(long long i = k; i < n; i++) //半開区間
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(),v.rend()
#define pb push_back
#define mkp make_pair
//入力
#define vin(v,N) for(long long i=0;i<N;i++) cin>>v.at(i)
#define lin(n) long long n;cin>>n
#define chin(x) char x;cin>>x;
#define sin(s) string s;cin>>s;
#define vlin(v,N) vector<long long>v(N);for(long long i=0;i<N;i++)cin>>v.at(i)

#define max(a,b) max((ll)a,(ll)b)
#define min(a,b) min((ll)a,(ll)b)

//関数
//最大公約数
long long gcd(long long m, long long n){
  long long a=max(m,n);
  long long b=min(m,n);
  long long r=a%b;
  while(r!=0){
    a=b; b=r; r=a%b;
  }
  return b;
}
// 最小公倍数
long long lcd(long long m, long long n){
  return m*n/gcd(m,n);
}
//xのn乗
long long power(long long x, long long N){
  long long ret=1;
  for(long long i=0;i<N;i++)   
    ret*=x;
  return ret;
}
//繰り返し二乗法
long long repeat_squaring(long long x, long long n){
  if(n==0) return 1;
  else if(n%2==0){
    long long t=repeat_squaring(x,n/2);
    return t*t%mod;
  }
  else
    return x*repeat_squaring(x,n-1)%mod;
}
//素因数分解(mapで返す)
map<int,int> factor(long long p){
  ll p1=p;
  map<int, int>ret;
  for(int i=2;i*i<=p1;i++){
     while(p%i==0){
      ret[i]++;
      p/=i;
    }
  }
  if(p!=1)
  ret[p]++;
  return ret;
}
//素数判定
bool is_prime(long long N){
  for(long long i=2;i*i<=N;i++){
    if(N%i==0)
      return false;
  }
  return true;
}
//最大値更新
void chmax(long long &a,long long b){
  a=max(a,b);
}
//最小値更新
void chmin(long long &a,long long b){
  a=min(a,b);
}

//構造体

//Union-Find木
struct UnionFind{
  //メンバ変数 
  vector<long long>par; //par[i]:=頂点iの親
  vector<long long>s; //s[i]:=頂点iが属する集合の個数(iが根のとき)
  
  //コンストラクタ
  UnionFind(long long N):par(N),s(N){
    for(long long i=0;i<N;i++){
      par[i]=i; //最初はすべてが根として初期化
      s[i]=1;
    }
  }
  //メンバ関数
  //root(i):=頂点iの根
  long long root(long long i){
    if(par[i]==i) return i;
    par[i]=root(par[i]); //経路圧縮
    return root(par[i]); //再帰
  }
  //size[i]:=iが属する集合の個数
  long long size(long long i){
    return s[root(i)];
  }
  //same(x,y) xとyが同じ根を持つか(同じ集合に含まれるか)
  bool same(long long x, long long y){
    return root(x)==root(y);
  }
  //unite(x,y) xの根をyの根に繋げる(集合を合併)
  void unite(long long x, long long y){
    if(!same(x,y)){
      long long rx=root(x);
      long long ry=root(y);
      par[rx]=par[ry];
      s[ry]=s[rx]+s[ry];
    }
  }
};

/////////////////⊂('ω'⊂ )))Σ≡GO!/////////////////


void cycle_calc(vector<ll>& a, int r, int p, ll &res, ll K){


  ll cycle = 0;
  for(int i = r; i < r + p; i++){
    cycle += a[i];
  }

  ll roop = K / p;
  ll remainder = K % p;
  res += cycle * roop;
  for(int i = r; i < r + remainder; i++){
    res += a[i];
  }
}

//メイン関数
int main(){
  //doubleの桁数
  
  ll N, X, M; cin >> N >> X >> M;

  vector<ll> roop_sercher(M, -1);
  vector<ll> a(3 * M);

  ll res = 0;
  ll r = -1;
  ll p = -1;
  ll K = N;


  rep(i, N){
    if(roop_sercher[X % M] != -1){
      r = roop_sercher[X];
      p = i - r;
      K = N - r - p;
      cycle_calc(a, r, p, res, K);
      //cout << X << " " << r << " " << p << endl;
      break;
    }
    res += X % M;
    a[i] = X % M;
    roop_sercher[X % M] = i;
    X = X * X % M;

  }
  

  cout <<res <<endl;
  //cout << p << " " << r << endl;
}
