#include<bits/stdc++.h>
using namespace std;
using ll = long long;
template<class T> using vt = vector<T>;
template<class T> using vvt = vector<vt<T>>;
template<class T> using ttt = tuple<T,T>;
using tii = tuple<int,int>;
using vi = vector<int>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define pb push_back
#define mt make_tuple
#define ALL(a) (a).begin(),(a).end()
#define FST first
#define SEC second
#define DEB cerr<<"!"<<endl
#define SHOW(a,b) cerr<<(a)<<" "<<(b)<<endl
#define DIV int(1e9+7)
const int INF = (INT_MAX/2);
const ll LLINF = (LLONG_MAX/2);
const double eps = 1e-8;
const double PI = M_PI;  
inline ll pow(ll x,ll n,ll m){ll r=1;while(n>0){if((n&1)==1)r=r*x%m;x=x*x%m;n>>=1;}return r%m;}
inline ll lcm(ll d1, ll d2){return d1 / __gcd(d1, d2) * d2;}

/* Coding Space*/
class FermatCombination{
public:
  vector<ll> factrial; // 階乗
  vector<ll> inverse; // 逆元
  FermatCombination(int size){
    factrial.resize(size+1);
    inverse.resize(size+1);
    factrial[0] = 1;
    inverse[0] = 1;
    for(int i = 1; i < size+1; i++){
      factrial[i] = factrial[i-1] * i % DIV;
      inverse[i] = pow(factrial[i],DIV-2,DIV);
    }
  }
  ll combination(int n, int k){
    if(n < k) return 0; 
    return factrial[n]* inverse[k] % DIV * inverse[n - k] % DIV;
  }
  ll permutation(int n, int k){
    if(n < k) return 0; 
    return factrial[n] * inverse[n-k] % DIV;
  }
  ll multi_choose(int n, int k){
    if(n == 0 && k == 0) return 1;
    else return combination(n+k-1,k);
  }
};

ll dp[1010][1010] = {}; // i : members of group, j : number of using.

int main(){
  int n,a,b,c,d; cin >> n >> a >> b >> c >> d;
  FermatCombination fc(n+1);
  rep(i,1010) dp[i][0] = 1;
  
  for(int i = a; i <= b; i++)
    for(int j = 0; j <= n; j++){
      if(dp[i][j] == 0) continue;
      if(j != 0){
        dp[i+1][j] += dp[i][j];
        dp[i][j] %= DIV;
      }
      ll tmp = 1;
      for(int k = 1; k <= d; k++){
        if(j + i * k > n) break;
        tmp *= fc.combination(n-j-i*(k-1), i ) * pow(k, DIV-2,DIV) % DIV;
        tmp %= DIV;
        tmp %= DIV;
        if(k >= c && k <= d){
          dp[i+1][j+i*k] += (1LL * dp[i][j] * tmp) % DIV;
          dp[i+1][j+i*k] %= DIV;
        }
      }
    }
  cout << dp[b+1][n] % DIV << endl;
}