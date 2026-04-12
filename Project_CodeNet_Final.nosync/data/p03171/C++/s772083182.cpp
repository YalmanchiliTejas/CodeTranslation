#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define dofloat cout<<fixed<<setprecision(8)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define bitcount __builtin_popcount
#define all(vec) vec.begin(),vec.end()
#define rall(vec) vec.rbegin(),vec.rend()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<long long> vl;
typedef pair<long long,long long> pll;
typedef vector<pair<long long,long long> > vll;
typedef vector<pair<int,int> > vii;
typedef vector<int> vi;
typedef pair<int,int> ii;
const long long MOD=1000000007;
const long long MAX=100005;
const long double PI=3.14159265359;
const long double G=9.807;
const long long INF=1e18;
const long double EPS=1e-6;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
bool isprime(ll a){
  if(a==2)return 1;
  if(!(a&1))return 0;
  for(ll i=3;i*i<=a;i+=2)
    if(a%i==0)return 0;
  return 1;
}
ll mpow(ll base,ll exponent,ll modulus){
  if(modulus==1)return 0;
  long long result = 1;
  base=base%modulus;
  while(exponent){
    if(exponent%2 == 1)
    result=(result*base)%modulus;
    exponent=exponent>>1;
    base=(base*base)%modulus;
  }
  return result;
}
ll minv(ll a,ll mod){
  ll _gcd=gcd(a,mod);
  assert(_gcd==1);
  return mpow(a,mod-2,mod);
}


/*
ll ncr(ll N,ll K){
  if(N<K)return 0;
  if(K==0)return 1;
  if(N==0)return 0;

  ll den=1;
  for(ll i=1;i<=K;i++)den*=i;
  ll num=1;
  while(K--){
    num*=N;
    if(num%den==0){
      num/=den;
      den=1;
    }
    N--;
  }

  return num;
}
*/
ll n;
ll a[3005],dp[3005][3005];
ll pre[3005];
int main(){FAST;
cin>>n;
for(ll i=1;i<=n;++i)cin>>a[i];
for(ll i=1;i<=n;++i){
  pre[i] = pre[i-1]+a[i];
}
for(ll i=1;i<=n;++i){
  dp[i][i] = a[i]; 
}
for(ll len=2;len<=n;++len){
  for(ll i=1,j=i+len-1;j<=n;++i,++j){
    dp[i][j] = max({dp[i][j],pre[j]-pre[i-1]-dp[i][j-1],pre[j]-pre[i-1]-dp[i+1][j]});
  }
}
cout<<2*dp[1][n]-pre[n];
return 0;
}

/*
 WA? check edge cases, N=1,M=1 etc. Read code fully once and check all variables.
 Read the question again and see what you might have missed.
 Consider changing your solution or find more cases.
 */
