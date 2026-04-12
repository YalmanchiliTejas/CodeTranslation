#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repo(i,n) for(int i = 1; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define np next_permutation
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define mod 1000000007
#define pi acos(-1.0)
const ll INF = 1LL<<61;
template<class T>bool chmax(T &a, const T &b) { 
  if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) {
  if (b<a) { a=b; return 1; } return 0; }
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }
ll jou(ll N, ll P){if(P==0) return 1;
  if(P%2==0){ll t = jou(N, P/2);return t*t % mod;
  }return (N * jou(N, P-1)) % mod;}  //jou(n,mod-2)で逆元
//intの最大値2147483647 ≒ 2×10^9
//long longの最大値9223372036854775807 ≒ 9×10^18
//'大文字'+=32;    で小文字に
//  cout << fixed << setprecision (20);   小数点以下2０桁まで
//実行時間制約2秒では２×10^8回くらいまで計算できる




int main(){
  int n;
  cin>>n;

  vector<ll> p(n);
  rep(i,n){
    cin>>p[i];
  }

  sort(all(p));

  ll ans;
  vector<ll> q(n);
  if(n%2==0){
    ll dai=0;
    ll dtan=p[n/2];
    ll stan=p[n/2-1];
    ll sho=0;
    for(int i=n/2+1;i<n;i++){
      dai+=p[i];
    }
    rep(i,n/2-1){
      sho+=p[i];
    }
    ans=2*dai+dtan-2*sho-stan;
  }
  else {
    ll dai=0;
    ll dt=p[n/2+1];
    ll dtan=p[n/2];
    ll sho=0;
    for(int i=n/2+2;i<n;i++){
      dai+=p[i];
    }
    rep(i,n/2){
      sho+=p[i];
    }
    ans=2*dai+dtan+dt-2*sho;
    
    dai=0;
    dt=p[n/2];
    dtan=p[n/2-1];
    sho=0;
    for(int i=n/2+1;i<n;i++){
      dai+=p[i];
    }
    rep(i,n/2-1){
      sho+=p[i];
    }
    chmax(ans,2*dai-dtan-dt-2*sho);
  }


  cout << ans << endl;
}