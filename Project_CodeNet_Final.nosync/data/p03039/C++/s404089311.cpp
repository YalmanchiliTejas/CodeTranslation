#include<bits/stdc++.h>
using namespace std;

#define ld long double
#define ll long long
#define ALL(a)  (a).begin(),(a).end()
#define spa << " " <<
#define MP make_pair
ll MOD = 1e9+7;
//ll MOD = 998244353;
ll INF = 1e18;
void chmin(ll &a, ll b) { if (a > b) a = b; }
void chmax(ll &a, ll b) { if (a < b) a = b; }
void ans1(bool x){
  if(x) cout<<"Yes"<<endl;else cout<<"No"<<endl;}
void ans2(bool x){
  if(x) cout<<"YES"<<endl;else cout<<"NO"<<endl;}
void ans3(bool x){
  if(x) cout<<"Yay!"<<endl;else cout<<":("<<endl;}
void ans(bool x, ll y, ll z){
  if(x) cout<<y<<endl;else cout<<z<<endl;}   

  const ll M = MOD;

vector<ll> fac(300001); //n!(mod M)
vector<ll> ifac(300001); //k!^{M-2} (mod M)
//a,bの範囲的にこれだけ配列を用意していけば十分

ll mpow(ll x, ll n){ //x^n(mod M) ←普通にpow(x,n)では溢れてしまうため，随時mod計算
    ll ans = 1;
    while(n != 0){
        if(n&1) ans = ans*x % M;
        x = x*x % M;
        n = n >> 1;
    }
    return ans;
}

ll comb(ll a, ll b){ //aCbをmod計算
    if(a == 0 && b == 0)return 1;
    if(a < b || a < 0)return 0;
    ll tmp = ifac[a-b]* ifac[b] % M;
    return tmp * fac[a] % M;
}

// mod. m での a の逆元 a^{-1} を計算する
// 逆元をかければ割ったことになる
ll modinv(ll a) {
    ll b = MOD, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= MOD;
    if (u < 0) u += MOD;
    return u;
}



int main(){
  ll i,j;
  ll n,m,k; cin>>n>>m>>k;
  //ll a,b,c,d,e,f; cin>>a>>b;
  //ll a,b,c,d,e,f; cin>>a>>b>>c;
  //ll a,b,c,d,e,f; cin>>a>>b>>c>>d;
  //string s; cin >> s;
  ll result = 0;
  ll buf = 0;
  ll buf2 = 0;
  ll buf3 = 0;
  bool judge = true;
  //cout<<<<endl;
  ll a[n][m];
  a[0][0]=0;
  for(i=1;i<n;i++)a[i][0]=a[i-1][0]+i;
  for(j=1;j<m;j++)a[0][j]=a[0][j-1]+j;
  for(i=1;i<n;i++){
    for(j=1;j<m;j++){
      a[i][j]=a[i][j-1]+a[i][0]+(i+1)*(j);
      //cout<<i spa j spa a[i-1][j] spa a[i][j-1] spa a[i][j]<<endl;
      a[i][j]%=MOD;
      //cout<<a[i][j]<<endl;
    }
  }
//for(i=0;i<n;i++)for(j=0;j<m;j++)cout<<a[i][j]<<endl;

  for(i=0;i<n;i++){
    for(j=0;j<m;j++){
      result+=a[i][j]+a[n-i-1][m-j-1]
      +a[n-i-1][j]+a[i][m-j-1]-
      a[0][j]-a[0][m-j-1]-a[n-i-1][0]-a[i][0];
      result%=MOD;
      //cout<<a[i][j]<<endl;
    }
  }
  result%=MOD;
  result*=modinv(2);
  result%=MOD;
  //cout<<result<<endl;
  fac[0] = 1;
    ifac[0] = 1;
    for(i = 0; i<300000; i++){
        fac[i+1] = fac[i]*(i+1) % M; // n!(mod M)
        ifac[i+1] = ifac[i]*mpow(i+1, M-2) % M; // k!^{M-2} (mod M) ←累乗にmpowを採用
    }
  ll q=0;
  q = comb(n*m-2, k-2)%M;
  result*=q;
  result%=MOD;
  //cout<<q<<endl;
  cout<<result<<endl;
  return 0;
}