#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
typedef long long ll;
#define rep(i,n) for(ll i=0, i##_len=(n); i<i##_len; ++i)
#define REP(i,num,n) for(ll i=num, i##_len=(n); i<i##_len; ++i)
#define repprev(i,a,b) for(ll i=b-1;i>=a;i--)
#define reprev(i,n) repprev(i,0,n)
using namespace std;
#define sz(x) ((int)(x).size())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
#define MEMSET(v, h) memset((v), h, sizeof(v))
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
template<class T> int former(const vector<T> &v, T x){
   return upper_bound(v.begin(),v.end(),x) - v.begin() - 1;
}
template<class T> int latter(const vector<T> &v, T x){
    return lower_bound(v.begin(),v.end(),x) - v.begin();
}
#define pb push_back
#define mp make_pair
using P = pair<ll,ll>;
using vl = vector<ll>;
using vb = vector<bool>;
using vs = vector<string>;
using vd = vector<double>;
using vc = vector<char>;
using vp = vector<P>;
#define V vector
#define o_vvt(o1, o2, o3, o4, name, ...) name
#define vvt0(t) V<V<t>>
#define vvt1(t,a) V<V<t>>a
#define vvt2(t,a, b) V<V<t>>a(b)
#define vvt3(t,a, b, c) V<V<t>> a(b,V<t>(c))
#define vvt4(t,a, b, c, d) V<V<t>> a(b,V<t>(c,d))
#define vvl(...) o_vvt(__VA_ARGS__,vvt4,vvt3,vvt2 ,vvt1,vvt0)(ll,__VA_ARGS__)
#define vvb(...) o_vvt(__VA_ARGS__,vvt4,vvt3,vvt2 ,vvt1,vvt0)(bool,__VA_ARGS__)
#define vvs(...) o_vvt(__VA_ARGS__,vvt4,vvt3,vvt2 ,vvt1,vvt0)(string,__VA_ARGS__)
#define vvd(...) o_vvt(__VA_ARGS__,vvt4,vvt3,vvt2 ,vvt1,vvt0)(double,__VA_ARGS__)
#define vvc(...) o_vvt(__VA_ARGS__,vvt4,vvt3,vvt2 ,vvt1,vvt0)(char,__VA_ARGS__)
#define vvp(...) o_vvt(__VA_ARGS__,vvt4,vvt3,vvt2 ,vvt1,vvt0)(P,__VA_ARGS__)
template<typename T> vector<T> make_v(size_t a) { return vector<T>(a); }
template<typename T, typename... Ts> auto make_v(size_t a, Ts... ts) {return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...));}
#define vni(name, ...) auto name = make_v<ll>(__VA_ARGS__)
#define vnb(name, ...) auto name = make_v<bool>(__VA_ARGS__)
#define vns(name, ...) auto name = make_v<string>(__VA_ARGS__)
#define vnd(name, ...) auto name = make_v<double>(__VA_ARGS__)
#define vnc(name, ...) auto name = make_v<char>(__VA_ARGS__)
#define vnp(name, ...) auto name = make_v<P>(__VA_ARGS__)
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
const ll LLINF = 1LL<<60;
const int INTINF = 1<<30;

const int MAX = 510000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

struct UnionFind {
    vector<ll> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

    UnionFind(ll n) : par(n, -1) { }
    void init(ll n) { par.assign(n, -1); }

    ll root(ll x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }

    bool issame(ll x, ll y) {
        return root(x) == root(y);
    }

    bool merge(ll x, ll y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y); // merge technique
        par[x] += par[y];
        par[y] = x;
        return true;
    }

    ll size(ll x) {
        return -par[root(x)];
    }
};

template <typename T>
vector<T> dijkstra(int s,vector<vector<pair<int, T> > > & G){
   const T INF = numeric_limits<T>::max();
   using P = pair<T, int>;
   int n=G.size();
   vector<T> d(n,INF);
   vector<int> b(n,-1);
   priority_queue<P,vector<P>,greater<P> > q;
   d[s]=0;
   q.emplace(d[s],s);
   while(!q.empty()){
     P p=q.top();q.pop();
     int v=p.second;
     if(d[v]<p.first) continue;
     for(auto& e:G[v]){
       int u=e.first;
       T c=e.second;
       if(d[u]>d[v]+c){
         d[u]=d[v]+c;
         b[u]=v;
         q.emplace(d[u],u);
       }
     }
   }
   return d;
}

int64_t power(int64_t x, int64_t n, int64_t mod) {
   int64_t ret = 1;
   while(n > 0) {
     if(n & 1) (ret *= x) %= mod;
     (x *= x) %= mod;
     n >>= 1;
   }
   return ret;
}

vector<int> sieve_of_eratosthenes(int n) {
   vector<int> primes(n);
   for (int i = 2; i < n; ++i)
      primes[i] = i;
    for (int i = 2; i*i < n; ++i)
      if (primes[i])
        for (int j = i*i; j < n; j+=i)
          primes[j] = 0;
    return primes;
}

struct Dice{
   int s[6];
   int &top()   {return s[0];}
   int &south() {return s[1];}
   int &east()  {return s[2];}
   int &west()  {return s[3];}
   int &north() {return s[4];}
   int &bottom(){return s[5];}
   void roll(char c){
     //the view from above
     // N
     //W E
     // S
     string b("EWNSRL");
     int v[6][4]={{0,3,5,2},
                  {0,2,5,3},
                  {0,1,5,4},
                  {0,4,5,1},
                  {1,2,4,3},
                  {1,3,4,2}};
     for(int k=0;k<6;k++){
       if(b[k]!=c) continue;
       int t=s[v[k][0]];
       s[v[k][0]]=s[v[k][1]];
       s[v[k][1]]=s[v[k][2]];
       s[v[k][2]]=s[v[k][3]];
       s[v[k][3]]=t;
     }
   }
   using ll = long long;
   ll hash(){
     ll res=0;
     for(int i=0;i<6;i++) res=res*256+s[i];
     return res;
   }
   bool operator==(const Dice &d) const{
     for(int i=0;i<6;i++) if(s[i]!=d.s[i]) return 0;
   return 1;
   }
  };
  vector<Dice> makeDices(Dice d){
   vector<Dice> res;
   for(int i=0;i<6;i++){
     Dice t(d);
     if(i==1) t.roll('N');
     if(i==2) t.roll('S');
     if(i==3) t.roll('S'),t.roll('S');
     if(i==4) t.roll('L');
     if(i==5) t.roll('R');
     for(int k=0;k<4;k++){
       res.push_back(t);
       t.roll('E');
     }
   }
   return res;
  }

// 多次元 vector 生成
template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
  return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}


std::vector<ll> divisor(ll n)//nの約数を列挙
{
 std::vector<ll> ret;
 for(ll i=1 ; i*i<=n ; ++i)
  {
   if(n%i == 0)
    {
     ret.push_back(i);
     if(i!=1 && i*i!=n)
     {
        ret.push_back(n/i);
      }
    }
  }
  return ret;
}

vector<pair<long long, long long> > prime_factorize(long long n) { //素因数分解、pairのfirstに底、secondに底の何乗
   vector<pair<long long, long long> > res;
   for (long long p = 2; p * p <= n; ++p) {
       if (n % p != 0) continue;
       int num = 0;
       while (n % p == 0) { ++num; n /= p; }
       res.push_back(make_pair(p, num));
   }
   if (n != 1) res.push_back(make_pair(n, 1));
   return res;
}

ll N, M;
using Graph = vector<vector<ll>>;
// 深さ優先探索
vector<bool> seen;
ll gdfs(const Graph &G, int v) {
    bool all_visited = true;
    seen[v] = true;
    rep(i,N){
      if(seen[i]==false) all_visited = false;
    }
  if(all_visited) return 1;
  int ans = 0;
    // v から行ける各頂点 next_v について
    for (auto next_v : G[v]) {
       if (seen[next_v]) continue; // next_v が探索済だったらスルー
       ans += gdfs(G, next_v); // 再帰的に探索
       seen[next_v] = false;
    }
    return ans;
}

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};


int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    ll a,b;
    Graph G(N);
    seen.resize(N);
    rep(i,M){
       cin >> a >> b;
       a--;
       b--;
       G[a].pb(b);
       G[b].pb(a);
    }
  cout << gdfs(G, 0) << endl;
    
}