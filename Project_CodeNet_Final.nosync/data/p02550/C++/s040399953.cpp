#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<tuple>
#include<vector>
#include<cstdlib>
#include<cstdint>
#include<stdio.h>
#include<cmath>
#include<limits>
#include<iomanip> 
#include<ctime>
#include<climits>
#include<random>
#include<queue>
#include<map>


using namespace std;

template <class T> using V = vector<T>;

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

const long long INF = 1LL << 60;
const double pi=acos(-1);

using ll = long long;
using vll = V<ll>;
using vpll =V<pair<ll,ll>>;
using graph = V<V<int>>;



#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define bgn begin()
#define en end()
#define SORT(a) sort((a).bgn,(a).en)
#define REV(a) reverse((a).bgn,(a).en)
#define fi first
#define se second
#define gcd(a,b) __gcd(a,b)
#define ALL(a)  (a).begin(),(a).end()



const int MAX = 5100000;
// change
const int MOD = 1000000007;
//const int MOD=998244353;

long long fac[MAX], finv[MAX], inv[MAX];

void Comuse() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}


#define comuse Comuse()

ll combi(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

ll perm(int n,int k){
    if(n < k) return 0;
    if(n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] % MOD) % MOD;
}

ll modpow(ll a,ll n,ll mod){
  ll ans=1;
  while(n>0){
    if(n&1){
      ans=ans*a%mod;
    }

    a=a*a%mod;
    n/=2;
  }

  return ans;
}

ll modinv(ll a, ll mod) {
    return modpow(a, mod - 2, mod);
}

ll modcombi(int n,int k,int mod){
  ll ans=1;
  for(ll i=n;i>n-k;i--){
    ans*=i;
    ans%=mod;
  }
  for(ll i=1;i<=k;i++){
    ans*=modinv(i,mod);
    ans%=mod;
  }

  return ans;
}


vll div(ll n){
  vll ret;
  for(ll i=1;i*i<=n;i++){
    if(n%i==0){
      ret.push_back(i);
      if(i*i!=n){
        ret.push_back(n/i);
      }
    }
  }
  SORT(ret);
  return (ret);
}

bool isprime(int p){
  vector<int> Check={2,3,5,7,11,13,17,19,23,29,31,37};
  bool ans=true;
  for(int i=0;i<12;i++){
    if(p%Check[i]==0 and p!=Check[i]){
      ans=false;
    }
  }

  return ans;
}


const int era=2000000;
long long sieve[era];

void Sieveuse(){
  for(ll i=1;i<era;i++){
    sieve[i]=i;
  }

  for(ll i=2;i<era;i++){
    for(ll j=2*i;j<era;j+=i){
      chmin(sieve[j],i);
    }
  }
}

ll lcm(ll a,ll b){
  return a/gcd(a,b)*b;
}

void bf(ll n,string s){
  for(ll i=0;i<n;i++){
    cout<<s;
  }
  cout<<"\n";

  return;
}


void Solve();


const int MAX_N = 131072;
//segment tree 
int NN;
int seg[MAX_N*2-1];
void seguse(){
  for(int i=0;i<2*NN-1;i++){
    seg[i]=INT_MAX;
  }
}




signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<setprecision(20)<<fixed;
  Solve();
}



/****************************************\
| Thank you for viewing my code:)        |
| Written by RedSpica a.k.a. RanseMirage |
| Twitter:@asakaakasaka                  | 
\****************************************/
//segtreeの葉の先頭の添え字はN-1
void Solve(){
  ll n,x,m;
    cin>>n>>x>>m;
  
  if(x==1){
    cout<<n<<"\n";
    return;
  }
  
  ll ans=0;

  vll A(m);
  vll B(m);
  A[0]=x;
  B[x]++;

  ll roop=m;
  ll roopN=0;
  ll all=x;
  bool zero=false;

  FOR(i,1,m){
    A[i]=modpow(A[i-1],2,m);
    B[A[i]]++;
    all+=A[i];
    
    if(A[i]==0){
      zero=true;
      break;
    }

    if(B[A[i]]==2){
      roop=i;
      roopN=A[i];
      break;
    }
  }
  
  if(n<=m){
    FOR(i,0,n){
      ans+=A[i];
    }

    cout<<ans<<"\n";
    return;
  }

  if(zero){
    FOR(i,0,m){
      ans+=A[i];
    }
    
    cout<<ans<<"\n";
    return;
  }

  
  ll l=-1,r=-1;
  FOR(i,0,m){
    if(A[i]==roopN and l==-1){
      l=i;
      continue;
    }

    if(A[i]==roopN and r==-1){
      r=i;
    }
  }

  FOR(i,0,l){
    ans+=A[i];
  }

  n-=l;

  if(roop!=m){
    all=0;
    for(int i=l;i<r;i++){
      all+=A[i];
    }
  }

  ans+=(n/(r-l))*all;
  n%=(r-l);
  for(int i=l;i<l+n;i++){
    ans+=A[i];
  }

  cout<<ans<<"\n";
}