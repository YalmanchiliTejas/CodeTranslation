#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
const ll mod = 1000000007;
// const int max = 510000;

ll fact[510000],fact_inv[510000];

ll power(ll a, ll b){
  ll res = 1;
  while(b>0){
    if(b&1) res=res*a%mod;
    a = a*a %mod;
    b>>=1;
  }
  return res;
}

ll combo(ll n, ll r){
    return ( fact[n] * fact_inv[r] ) %mod * fact_inv[n-r] %mod;
}

int main(){
  ll N,M,K;cin>>N>>M>>K;
  ll i,j,k,l;
  fact[0]=1;
  repn(i,N*M){
    fact[i] = fact[i-1] * i %mod;
  }
  fact_inv[N*M] = power(fact[N*M] , mod-2);
  for(i=N*M-1;i>=0;i--){
    fact_inv[i] = fact_inv[i+1]*(i+1) %mod;
  }
  ll ans=0;
  repn(i,N){
    ans+=i*(N-i)*M*M;
    ans%=mod;
  }
  repn(i,M){
    ans+=i*(M-i)*N*N;
    ans%=mod;
  }
  // cout<<ans<<endl;
  ans*=combo(N*M-2,K-2);
  ans%=mod;
  cout<<ans<<endl;
}
