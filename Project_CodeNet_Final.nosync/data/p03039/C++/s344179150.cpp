#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) x.begin(),x.end()
#define dmp(x) cerr<<#x<<":"<<x<<endl
#define FOR(i,a,b) for(int i=(int)a,c=(int)b;i<c;++i)
#define rep(i,b) FOR(i,0,b)
#define ROF(i,a,b) for(int i=b-1,c=(int)a;i>=c;--i)
#define per(i,b) ROF(i,0,b)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

struct Comb{
  
  vector<int> fact,infact;
  int mod;
  
  Comb(int n,int m=1e9+7):
    fact(n+1),
    infact(n+1),
    mod(m)
  {
    n++;
    fact[0] = 1;
    for( int i = 1 ; i < n ; i++ ){
	 fact[i] = fact[i-1] * i;
	 fact[i] %= mod;
    }
    for( int i = 0 ; i < n ; i++ ){
	 infact[i] = mod_pow( fact[i] , mod-2 );
    }
  }

  int mod_pow(int x,int n){
    if(n==0)return 1;
    int res=mod_pow( x*x%mod , n/2 );
    if( n & 1 )res = res*x%mod;
    return res;
  }

  int comb(int a,int b){
    if(a == 0 && b == 0)return 1;
    if(a < b || a < 0)return 0;
    int tmp = infact[a-b]* infact[b] % mod;
    return tmp * fact[a] % mod; 
  }

  int perm(int a,int b){
    if(a == 0 && b == 0)return 1;
    if(a < b || a < 0)return 0;
    return fact[a] * infact[a-b] % mod;
  }
};


signed main(){
  int n,m,k,mod=1000000007;
  cin>>n>>m>>k;
  Comb c(n*m);
  int ans=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
	 ans+=((m-j-1)*(m-j)/2%mod)*(n-i)%mod;
	 ans%=mod;
	 ans+=((j)*(j+1)/2%mod)*(n-i-1)%mod;
	 ans%=mod;
	 ans+=((n-i-1)*(n-i)/2%mod)*m%mod;
	 ans%=mod;
    }
  }
  ans*=c.comb(n*m-2,k-2);
  cout<<ans%mod<<endl;
  return 0;
}
