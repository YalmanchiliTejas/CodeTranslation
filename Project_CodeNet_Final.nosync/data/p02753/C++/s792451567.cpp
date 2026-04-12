#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>
#include <queue>
#include <cstdio>
using namespace std;

template <class T> using V = vector<T>;
template <class S, class T> using P = pair<S, T>;
template <class... T> using TP = tuple<T...>;

using ll = long long;
using db = double;
using ldb = long db;
using str = string;
using vll = V<ll>;
using vvll = V<V<ll>>;
using vvvll = V<V<V<ll>>>;
using pll = P<ll,ll>;
using tpll = TP<ll,ll,ll>;
using vpll =V<pll>;
using vvpll = V<vpll>;
using vtpll = V<tpll>;
using vst = V<str>;
using vch = V<char>;
using vvch = V<vch>;
using dqll = deque<ll>;
using vdqll = V<dqll>;
using pqll = priority_queue<ll>;
using pqpll = priority_queue<pll>;
using vpqll = V<pqll>;
using mll = map<ll,ll>;
using vmll = V<mll>;
using sll = set<ll>;
using msll = multiset<ll>;

#define FOR(i,a,b) for(ll i=(a);i<(ll)(b);i++)
#define rep(i,b) for(ll i=0;i<(ll)(b);i++)
#define rFOR(i,a,b) for(ll i=(ll)(a);i>=(b);i--)
#define bg begin()
#define rbg rbegin()
#define en end()
#define SORT(a) sort((a).bg,(a).en)
#define REV(a) reverse((a).bgn,(a).end())
#define fi first
#define se second
#define sz size()
#define gcd(a,b) __gcd(a,b)
#define co(a) cout<<a<<endl
#define ins(a) insert(a)
#define pb(a) push_back(a)
#define pf(a) push_front(a)
#define ba back()
#define fr front()
#define pob pop_back()
#define pof pop_front()
#define mp make_pair
#define mt make_tuple
#define pbmp(a,b) push_back(mp(a,b))
#define lb(a) lower_bound(a)
#define ub(a) upper_bound(a)
#define subs(a,n) substr(a,n)
#define cfs(a) cout<<fixed<<setprecision(a) 

/*vvll v(n,vll(m)) n行m列  continue
A.erase(A.begin()+i); 配列Aのi番目を消せる
if(std::binary_search(v.bg,v.en,a)){ 二分探索
abs(a,b)   pow(a,n)  to_string(int)  stoll(string)
auto Iter=lower_bound(v.bg,v.en,a); v[i]>=aとなる初のv[i]
v.insert(lower_bound(v.bg,v.en,a),b); bを入れられる
lower upper  co(*Iter)    co(Iter-v.bg) -> v[i]>=aとなる初のi
vvll v(100001,vll(0)); v[a].pb(b); v[b].pb(a);
pqll pq; pq.push(ai); pq.top(); pq.pop();
pqpll qu; pll pa; qu.push(mp(ai,i)); pa=qu.top();
priority_queue<ll,vll,greater<ll>> pqg; 昇順
vdqll dq(3);  dq[0].pb(1); dq[0].pb(2); dq[0].pf(0);
dq[0].fr→0 dq[0].ba→2 dq[0].pof; dq[0].fr→1
while(que.sz) while(!que.empty()) 
ll a=1,b=2,c=4,xo; xo=a^b^c; if(a^b^c==7)co(xo)→なし(miss) if(xo==7)co(xo)→7 
a<<b→a*2^b a>>b→a/2^b
FOR(i,0,1<<20){FOR(j,0,20){if((i>>j)&1)→iの二進で1となる桁のjのみ 
mll m; FOR(i,0,n){cin>>v[i]; m[v[i]]++;} if(m.count(key))
for(pll p:m){ll key=p.fi; ll val=p.se;}
sll s; s={0,5,7}; s.ins(0); s.ins(2); if(s.count(2))s.erase(2); co(s.sz)→3
for(ll x:s)co(x); for(auto it=s.bg;it!=s.en;it++)co(*it);→0,5,7
auto i=s.bg;co(*i)→0; auto it=s.rbg;co(*it)→7; auto ite=s.en;co(*ite)→3
co(*it)→7; it++;co(*it)→5; it++;co(*it)→0; it++;co(*it)→3
auto it=rbg; FOR(i,0,s.sz){co(*it);it++;}→7,5,0
auto it=s.lb(5);co(*it)→5; it++;co(*it)→7; it--;it--;co(*it)→0;
auto calc=[&](ll x){...}; 最後に;が必要 ローカル内で関数を作れる
*/
/*
ll by=pow(3,10);
FOR(i,0,by){
  ll div=1,rem=i;
  FOR(j,0,10){
    rem/=div;
    if(rem%3==0){}if(rem%3==1){}if(rem%3==2){}
    div*=3,rem=i;}}
    //10人が3択のどれを選ぶかの総当たり
*/

const int MAX = 1'000'005;
const int MOD = 1'000'000'007;
long long fac[MAX], finv[MAX], inv[MAX];
void Comuse() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;//inv[i]*i%MOD→1
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
#define comuse Comuse() //マイナスにならないように注意
ll combi(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
ll pow_mod(ll a,ll n,ll mod){
  ll res=1;        //n=k_2  pow(a,k_2)
  for(;n>0;n/=2){  //ex,pow(a,1011_2)=a^8*a^2*a^1
    if(n%2==1)res=(res*a)%mod;
    a=(a*a)%mod;
  }
  return res;
}
ll digit_sum(ll n) {
  ll m=0;
  FOR(i,0,20){
    m+=n%10;
    n/=10;
    if(n==0)break;
  }
  return m;
}
ll lcm(ll a,ll b){
  ll n;
  n=a/gcd(a,b)*b;
  return n;
}


int main(){
  str s;
  cin>>s;
  if(s=="AAA"||s=="BBB"){
    co("No");
  }
  else{
    co("Yes");
  }
}
  