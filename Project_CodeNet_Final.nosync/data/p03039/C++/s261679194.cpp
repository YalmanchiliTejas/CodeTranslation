#include <bits/stdc++.h>
using namespace std; 

// #pragma GCC optimize("Ofast")
// #pragma GCC optimize ("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

typedef long long ll; 
typedef long double ld; 
typedef pair<int,int> p32;   
typedef pair<ll,ll> p64;  
typedef pair<double,double> pd; 
typedef pair<ld,ld> pld; 
typedef vector<int> v32;  
typedef vector<ll> v64;  
typedef vector<pd> vpd;   
typedef vector<p32> vp32;  
typedef vector<p64> vp64;  
typedef vector<v32> vv32;  
typedef vector<v64> vv64;  

#define pb push_back
#define mp make_pair
#define prarr(a,n) cerr<<#a<<" : ";for(ll i=0;i<n;i++) cerr<<a[i]<<" "; cerr<<endl;
#define prmat(mat,row,col) cerr<<#mat<<" :\n";for(ll i=0;i<row;i++) {for(ll j=0;j<col;j++) cerr<<mat[i][j]<<"\t";cerr<<endl;}
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
#define all(a) a.begin(),a.end()
#define sz(x) ((int)x.size())
#define endl '\n'
#define fast_io ios_base::sync_with_stdio(NULL); cin.tie(NULL)
template <class T> void dbs(string str, T t) {cerr << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {ll idx = str.find(','); cerr << str.substr(0, idx) << " : " << t << ", "; dbs(str.substr(idx + 1), s...);}
template <class T> void prc(T a, T b) {cerr << "["; for (T i = a; i != b; ++i) {if (i != a) cerr << ", "; cerr << *i;} cerr << "]\n";}
template <class T> void prall(T a) { prc(all(a)); }


const int inf=1000*1000*1000+9; 
const ll infl=1ll*inf*inf; 
int mod=1000*1000*1000+7;  
// ---------------------------------------------------------------------------- -------------- 



ll choose(int n, int r){
  v64 fac(n+1,1), ifac(n+1,1), inv(n+1,1);   
  for(int i=2;i<=n;i++){
    fac[i]=fac[i-1]*i%mod; 
    int r=mod%i, q=mod/i; 
    inv[i]=mod-q*inv[r]%mod; 
    ifac[i]=ifac[i-1]*inv[i]%mod; 
  }
  return fac[n]*ifac[n-r]%mod*ifac[r]%mod; 
}

void solve(){
  ll n,m,k; 
  cin>>n>>m>>k; 
  ll ans=0;  
  for(ll i=1;i<=n;i++){
    for(ll j=1;j<=m;j++){
      ans+=((j-1)*j/2)*(n-i) + (m-j)*(m-j+1)/2*(n-i+1) +(n-i)*(n-i+1)/2*m; 
      ans%=mod; 
    }
  }
  ans*=choose(n*m-2,k-2); 
  ans%=mod; 
  cout<<ans<<endl; 
  return;
}


int main(){
	// clock_t beg=clock(); 
  fast_io; 
  int testcases=1; 
  // cin>>testcases; 
  cout << fixed << setprecision(13); 
  while(testcases--){
    solve(); 	
  }
	// clock_t end=clock(); 
	// fprintf(stderr, "%lf\n", (double)(end-beg)/(CLOCKS_PER_SEC));
}
