#include<bits/stdc++.h>
using namespace std;
 
#define MOD 1000000007
#define N 100010
 
typedef double lf;
typedef long long ll;
#define int ll
typedef long double ld;
typedef unsigned long long ull;
typedef set<ll> sll;
typedef vector<ll> vll;
typedef vector<pair<ll,ll > >vpll;
typedef vector<vll > vvll;
#define endl "\n"
#define sd(a) scanf("%d",&a)
#define sstr(a) scanf("%s",a)
#define sl(a) scanf("%lld",&a)
#define debug(a) printf("check%d\n",a)
#define clr(a) memset(a,0,sizeof(a))
#define rtn return 
#define gc getchar
#define pb push_back
#define ff first
#define ss second
#define mp(x,y) make_pair(x,y)
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define lp(i,b) for(ll i = ll(0); i<ll(b) ; i++) 
#define lpit(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define mid(s,e) (s+(e-s)/2)
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define fast ios_base::sync_with_stdio(NULL),cin.tie(0),cout.tie(0);
ll ip(){
  ll x = 0; bool isNeg = false; char c;
  c = gc();
  if(c == '-')  isNeg = true , c = gc();
  for( ; c >= '0'  && c <= '9' ; c = gc()); x = (x << 1) + (x << 3) + c - '0';
  if(isNeg) x *= -1;  return x;
}
//////////////////////////////////////////// CONTAINERS FOR FUNCTIONS MENTIONED IN TEMPLATE ///////////////////////////////////
#define MAX 100005
//bool isPrime[MAX];
//int spf[MAX];
//////////////////////////////////////////// FUNCTIONS THAT NEED COMMENTED OUT CONTAINERS ////////////////////////////////////
 
 
//void prime_sieve(){ for(ll i=2 ; i*i<=MAX ; i++){ if(!isPrime[i]){ for(ll j=i*i ; j<=MAX ; j+=i)  isPrime[j] = 1;} }  }
//void spf_sieve(){ for(ll i=2 ; i<MAX ; i+=2)  spf[i] = 2;
//  for(ll i=3 ; i<MAX ; i+=2){ if(!isPrime[i]){ spf[i] = i; for(ll j=i ; (j*i)<MAX ; j+=2){ if(!isPrime[i*j])  isPrime[i*j] = true , spf[i*j] = i; } } }
//}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// inline ll ncr(ll n,ll r){ ll ans = 1 ; if(r > n-r) r = n-r; lp(i,r+1){ans*=(n-i) ; ans/=(i+1); } rtn ans; }
inline ll gcd(ll a,ll b){if(!a) rtn b; rtn gcd(b%a,a); }
inline ll fme(ll x,ll n){ll ans=1;x%=MOD;while(n>0){if(n&1){ ans*=x;ans%=MOD;} x*=x;x%=MOD;n>>=1;}rtn ans%MOD;}
inline bool isPalin(string &s){ int len = s.size()-1;lp(i,(len/2)+2){if(!(s[i]==s[len-i]))  rtn false;} rtn true;}
inline ll lcm(ll a,ll b){rtn (a*b)/gcd(a,b); }
inline ll fmm(ll a,ll b) {ll r=0;a%=MOD;b%=MOD;while(b>0){if(b&1){r+=a;r%=MOD;}a+=a;a%=MOD;b>>=1;}rtn r%MOD;}
inline ll sfme(ll a,ll b) {ll r=1;a%=MOD;while(b>0){if(b&1)r=fmm(r,a);a=fmm(a,a);b>>=1;}rtn r%MOD;}
inline int in(){ int NR=0; register char c=gc(); while( c < 48 || c > 57 ){c=gc();} 
  while(c>47 && c< 58){ NR = (NR << 3) + (NR << 1) + (c - 48); c=gc();} return NR;
}
 
ll dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};
//--------------------------------TEMPLATE ENDS HERE--------------------------------------------------//
#define NMAX 100005
#define LOGNMAX 20
int f[NMAX];
 
int power(int a,int b){if(b==0){return 1;}int s=power(a,b/2);s*=s;s%=MOD;if(b&1){return (s*a)%MOD;}return s;}
 
int inv(int a){return power(a,MOD-2);}
 
int nCr(int n,int r){if(n<0 || r<0){return 0;}int ans=0;ans=f[n];ans*=inv(f[r]);ans%=MOD;ans*=inv(f[n-r]);ans%=MOD;return ans;}
 
int ncr(int n,int r){if(r==0){return 1;}if(n-r<r){r=n-r;}int ans=1;for(int i=0;i<r;i++){ans*=(n-i);ans/=(i+1);}return ans;}
 
int dp[10005][2][100][2];
string k;
int d;
int fi(int pos,bool flag,int rem,bool started,string &s){
	if(pos==s.length()){
		return started && (rem%d==0);
	}
	int &res=dp[pos][flag][rem][started];
	if(res!=-1){
		return res;
	}
	res=0;
	int limit=9;
	if(flag==0){
		limit=s[pos]-'0';
	}
	for(int i=0;i<=limit;i++){
		res+=fi(pos+1,flag|(i<s[pos]-'0'),(rem+i)%d,started|i,s);
		res%=MOD;
	}
	return res;
}
 
signed main(){
	fast;	
	// f[0]=1;
	// for(int i=1;i<NMAX;i++){
	// 	f[i]=(f[i-1]*i)%MOD;
	// }
	
 	cin>>k>>d;

 	memset(dp,-1,sizeof dp);
 	// cout<<k<<endl;
 	int ans=fi(0,0,0,0,k);
 	ans=(ans%MOD+MOD)%MOD;
 	cout<<ans<<endl;
	
 
}