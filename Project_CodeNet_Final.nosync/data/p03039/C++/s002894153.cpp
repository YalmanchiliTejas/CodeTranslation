#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef unsigned long long int ulli;
typedef pair<int,int> pii;

#define ones(x) __builtin_popcount(x)
#define onesl(x) __builtin_popcountl(x)
#define onesll(x) __builtin_popcountll(x)

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define scn(n) scanf("%d",&n)
#define scnll(n) scanf("%lld",&n)
#define scn2(n,m) scanf("%d%d",&n,&m)
#define scn3(n,m,w) scanf("%d%d%d",&n,&m,&w)
#define scn2ll(n,m) scanf("%lld%lld",&n,&m)
#define atoz(v) v.begin(),v.end()
#define ratoz(v) v.rbegin(),v.rend()
#define Fill(a,v) memset(a,v,sizeof(a))
#define sz(v) v.size()
#define fi first
#define se second
#define inf 1e9
#define pi acos(-1.0)
#define sqr(x) x*x
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define ten(n) (int)1e##n
#define tenll(n) (lli)1e##n
#define mod 1000000007
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

//#define long long ll
#define INF 1000000007
#define N 300005

long long f[N];


long long pow(long long a, long long b, long long MOD)
{
 long long x=1,y=a;
 while(b > 0)
 	{
 		if(b%2 == 1)
 	{
 		x=(x*y);
 		if(x>MOD) x%=MOD;
 	}
 	y = (y%mod * y%mod);
 	if(y>MOD) y%=MOD;
 	b /= 2;
 	}
 return x;
}

/* Modular Multiplicative Inverse
 Using Euler's Theorem
 a^(phi(m)) = 1 (mod m)
 a^(-1) = a^(m-2) (mod m) */
long long InverseEuler(long long n, long long MOD)
{
 return pow(n,MOD-2,MOD);
}

long long C(long long n, long long r, long long MOD)
{

 return (f[n]*((InverseEuler(f[r], MOD) * InverseEuler(f[n-r], MOD)) % MOD)) % MOD;
}

lli SUM(lli n){
    n = n*(n+1);
    n /= 2;
    n %= mod;
    return n;
}

lli add(lli a , lli b){
    return (a+b)%mod;
}

lli mul(lli a, lli b){

    return (a%mod * b%mod)%mod;
}

int main(){
	f[0] = 1;

	for(int i = 1 ; i < N ; i++) f[i] = mul(f[i-1],i);

 	int n,m,k;
 	scn3(n,m,k);

 	lli suma = 0, sumb = 0;

 	for(int i=n-1; i ; i--) suma = add(suma, SUM(i));
 	for(int i=m-1; i ; i--) sumb = add(sumb, SUM(i));

 	lli c = C((n*m-2+mod)%mod , k-2 , mod);

 	lli ans = mul(mul(c,m*m),suma) + mul(mul(c,n*n),sumb);
 	cout<<ans%mod;

 	return 0;
}
