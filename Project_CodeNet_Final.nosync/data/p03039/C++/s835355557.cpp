#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using ld  = long double;
using pll = pair<ll, ll> ;
using pld = pair<ld, ld>;
const int INF=1e9+7;
const ll LINF=1LL<<60 ;
const ll MOD=1e9+7;
const ld PI=acos(-1);
const ld EPS = 1e-9; //微調整用（EPSより小さいと0と判定など）
 
#define gcd __gcd //llは受け取ってくれない
int lcm(int a, int b){return a / gcd(a, b) * b;}
#define ALL(a) a.begin(),a.end() //sort(ALL(vec));
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define MP(a,b) make_pair(a,b)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define PB push_back
#define SZ(x) ((int)(x).size) //size()がunsignedなのでエラー避けに
 
//最大値、最小値を更新する。aよりbのが大きい（小さい）か等しければaを更新してtrueを返す。そうでなければ何もせずfalseを返す chmax(nowmax,x);
template<typename T>
bool chmax(T& a, T b){return (a = max(a, b)) == b;}
template<typename T>
bool chmin(T& a, T b){return (a = min(a, b)) == b;}
// ----- template end ---- //
 
// ------- library ------- //

ll modpow(ll x, ll n){return n < 2 ? x : modpow(x * x, n / 2) * (n % 2 ? x : 1) % MOD;}

//nCk,nPk,nHk(mod MOD)の計算　n!とk!^{MOD-2}を前計算して求める
//n(nHkを使う場合はn+k)の最大値を設定すること（10^7で581ms 236MB, 3*10^7で1496ms 705MB）
ll maxNplsK = 300000; // n+kの最大値を代入(0 < n, k <= maxNplsK) nHkを使わないならmaxNでもいい
vector<ll> fac(maxNplsK+1); //i!(mod MOD) を格納。
vector<ll> inv(maxNplsK+1); //i^-1(iのモジュラ逆数 mod MOD)を格納
vector<ll> finv(maxNplsK+1); //i!^-1(i!のモジュラ逆数 mod MOD)


//aCbをmod計算
ll comb(ll a, ll b){
  if(a == 0 && b == 0)return 1;
  if(a < b || a < 0)return 0;
  ll tmp = finv.at(a - b)* finv.at(b) % MOD;
  return tmp * fac.at(a) % MOD;
}

// ----- library end ----- //



int main() {
    
  ll H, W, K;
  cin >> H >> W >> K;

  //使う前に置いておく前計算（main()内でok）
  //大した量ではないので，先にfac[i]とifac[i]を全て計算しておく
  fac.at(0) = fac.at(1) = 1;
  finv.at(0) = finv.at(1) = 1;
  inv.at(1) = 1;
  for (int i = 2; i < maxNplsK+1; i++){
    fac.at(i) = fac.at(i - 1) * i % MOD;
    inv.at(i) = MOD - inv.at(MOD % i) * (MOD / i) % MOD;
    finv.at(i) = finv.at(i - 1) * inv.at(i) % MOD;
  }



  ll hwm2Ckm2; //HW-2 C K-2を計算

  if (K==2){
    hwm2Ckm2 = 1;
  }
  else if (K==3){
    hwm2Ckm2 = H*W - 2; //残りコマ1なので、その1つをどこに置くか
  }
  else{
    hwm2Ckm2 = 1;
    rep(i, K-2){ //単純にH*W-2から、1減らしながらK-2回掛ける
      hwm2Ckm2 = hwm2Ckm2 * (H*W-2 -i) % MOD;
    }
    //(K-2)!で割る
    hwm2Ckm2 = hwm2Ckm2 * finv.at(K-2) % MOD;
  }
//  cout << hwm2Ckm2 << endl;


  // |yi-yj|の合計
  ll ymy = 0;
  rep(i, H-1){
    ll d = i + 1;
    ymy += modpow(W, 2) * (H - d) % MOD * d % MOD;
  }

  ll xmx = 0;
  rep(i, W-1){
    ll d = i + 1;
    xmx += modpow(H, 2) * (W - d) % MOD * d % MOD;
  }

  cout << (ymy + xmx) % MOD * hwm2Ckm2 % MOD << endl;


// -- main() end -- //
}


 