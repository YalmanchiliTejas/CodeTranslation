#include <bits/stdc++.h>
#define GET_MACRO(_1,_2,_3,_4,_5,_6,NAME,...) NAME
#define pr(...) GET_MACRO(__VA_ARGS__,pr6,pr5,pr4,pr3,pr2,pr1)(__VA_ARGS__)
#define Pr(a) (#a)<<"="<<(a)<<" "
#define pr1(a) cerr<<Pr(a)<<endl;
#define pr2(a,b) cerr<<Pr(a)<<Pr(b)<<endl;
#define pr3(a,b,c) cerr<<Pr(a)<<Pr(b)<<Pr(c)<<endl;
#define pr4(a,b,c,d) cerr<<Pr(a)<<Pr(b)<<Pr(c)<<Pr(d)<<endl;
#define pr5(a,b,c,d,e) cerr<<Pr(a)<<Pr(b)<<Pr(c)<<Pr(d)<<Pr(e)<<endl;
#define pr6(a,b,c,d,e,f) cerr<<Pr(a)<<Pr(b)<<Pr(c)<<Pr(d)<<Pr(e)<<Pr(f)<<endl;
#define int long long
#define double long double
using namespace std;
const int N = 100010;
const int INF = 1LL<<55;
int mod = (1e9)+7;
const double EPS = 1e-8;
const double PI = 6.0 * asin(0.5);
typedef pair<int,int> P;
typedef long long ll;
template<class T> T Max(T &a,T b){return a=max(a,b);}
template<class T> T Min(T &a,T b){return a=min(a,b);}
ostream& operator<<(ostream& o,P p){return o<<"("<<p.first<<","<<p.second<<")";}
istream& operator>>(istream& i,P &p){return i>>p.first>>p.second;}
ostream& operator<<(ostream& o,vector<auto> &a){int i=0;for(auto t:a)o<<(i++?" ":"")<<t;return o;}
istream& operator>>(istream& i,vector<auto> &a){for(auto &t:a)i>>t;return i;}
void prArr(auto a,string s=" "){int i=0;for(auto t:a)cout<<(i++?s:"")<<t;cout<<endl;}

class Math{
public:
  typedef long long ll;
  ll mod;
  Math(ll mod = 1e9+7):mod(mod){}
  
  ll mod_pow(ll a,ll x, ll mod = -1){
    if(mod == -1) mod = this->mod; 
    ll res=1;
    while(x){
      if(x%2) res=res*a%mod;
      a=a*a%mod;
      x/=2;
    }
    return res;
  }

  //逆元
  ll inv(ll a){return mod_pow(a,mod-2);}

  //階乗関数
  ll K(int i, int n = 1e6){
    static vector<ll> k(n);
    if(!k[0]){k[0]=1;for(int i=1;i<(int)k.size();i++)k[i]=i*k[i-1]%mod;}
    return k[i];
  }

  //O(log(mod))  階上テーブルを使うので、k,rが大きすぎるとダメ。
  ll nCr(ll n,ll r){
    ll a = inv( K(r) * K(n-r) % mod);
    return K(n) * a % mod;
  }

  //O(r + log(mod))
  ll nCr2(ll n,ll r){
    ll N = 1, K = 1; 
    for(int i=0;i<r;i++) N=N*((n-i)%mod)%mod;
    for(int i=0;i<r;i++) K=K*((r-i)%mod)%mod;
    ll R = inv(K);
    return N*R%mod;
  }
  
  /*カーマイケル数ってなんだっけ忘れた*/
  static ll carmichaelLambda(ll n){
    ll res = 1;
    if(n % 8 == 0) n/=2;
    auto lcm = [](ll a,ll b){return (a/__gcd(a,b)) * b;};
    
    auto compute = [&](ll i){
      ll sub = i - 1;
      n/=i;
      while(n%i == 0) n/=i, sub *=i;
      res = lcm(res,sub);
    };
    
    for(int i=2;i*i<=n;i++) if( n % i == 0) compute(i);
    if(n != 1) compute(n);
    return res;
  }

  //n以下の素数を返す。  
  static vector<int> getPrime(int n){
    vector<bool>used(n+1,0);
    
    for(ll i=2;i*i<=n;i++)
      if(!used[i]) for(int j=2;j<=n/i;j++) used[i*j]=1;
    
    vector<int> res;
    for(int i=2;i<=n;i++)if(!used[i]) res.push_back(i);

    return res;
  }
  
  //素数判定
  static bool isPrime(ll n){
    if(n < 2) return 0;
    for(ll i=2;i*i<=n;i++) if(n%i==0) return 0;
    return 1;
  }

  //素因数分解 x == 0 || x == 1のときはその値自身を返す。
  static vector<ll> primeFactor(ll x){
    //if(x < 2) return {x}; /*!!!!!!!!!!!!!!!!!!!*/
    assert(x > 1);/*!!!!!!!!!!!!!!!!!!!*/

    vector<ll> res;
    for(ll i=2;i*i <= x;i++)
      while(x%i == 0){
        x/=i;
        res.push_back(i);
      }
    if(x != 1) res.push_back(x);
    return res;
  }

  static map<ll,ll> primeFactorMap(ll x){

    map<ll,ll> res;
    //if(x < 2) {
    //res[x]++;
    //  return res; /*!!!!!!!!!!!!!!!!!!!*/
    //}
    
    assert(x > 1); /*!!!!!!!!!!!!!!!!!!!*/
    
    for(ll i=2;i*i <= x;i++)
      while(x%i == 0) x/=i, res[i]++;
    
    if(x != 1) res[x]++;
    return res;
  }
  
  static ll divisor_Sum(map<ll,ll> prime){ // first : prime  second : cnt
    ll res = 1;
    for(P p : prime){
      ll sum = 1, mul = p.first;
      for(ll i=0;i<p.second;i++) sum += mul, mul *= p.first;
      res *= sum;
    }
    return res;
  }
  
  static ll divisor_Sum(ll num){
    return divisor_Sum(primeFactorMap(num));
  }
  
  //約数列挙
  static vector<ll> divisor(ll x){
    vector<ll> res;
    for(ll i=1; i*i<=x ;i++)
      if(x%i==0){
        res.push_back(i);
        if(i*i!=x) res.push_back(x/i);
      }
    sort(res.begin(), res.end());
    return res;
  }

  //a * bがオーバフローするか判定
  static bool overflow(ll a,ll b){return a > LONG_MAX/b;}

};
Math math;


int pow(int x){// 2^2^(x);
  int a = math.mod_pow(2, x, mod-1);
  return math.mod_pow(2, a, mod);
}

bool used[3001][3001];
int mem[3001][3001];
int dfs(int x, int y){ //topping , ramen count
  if(x == 0 && y == 0) return 1;
  if(x < y) return 0;
  if(y < 0) return 0;
  if(used[x][y]) return mem[x][y];
  used[x][y] = 1;
  int a = dfs(x-1, y-1); // 000...01?????を注文
  int b = y * dfs(x-1, y); //これからの注文にx番目の具材を１個使う
  int c = dfs(x-1, y); //x番目の具材を０個使う
  int res = (a + b + c)%mod;
  return mem[x][y] = res;
}

int n;
int calc(int x){
  int res = 0;
  for(int y=0;y<=x;y++){
    int a = dfs(x,y);
    int b = math.mod_pow( math.mod_pow(2,n - x), y ); //残りのビットの組み合わせ。
    res = (res + a*b) % mod;
  }
  //assert(pow(n-x) == math.mod_pow(2, pow(2, n-x)));
  res *= pow(n-x);
  res %= mod;
  return res;
}

signed main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  cin>>n>>mod;
  math = Math(mod);
  
  int sum = 0;
  for(int i=1;i<=n;i++){
    int f = i%2==1? 1:-1;
    int a = calc(i);
    int b = math.nCr(n,i);
    sum = sum + mod + f * a * b % mod;
    sum %= mod;
  }
  int ans  = (mod + pow(n) - sum)%mod;
  cout<<ans<<endl;
  return 0;
}
