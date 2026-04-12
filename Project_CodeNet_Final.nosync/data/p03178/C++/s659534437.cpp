//----AUTHOR:kkdrummer----/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef    long long   ll;
typedef    long double   ld;
//typedef    unordered_set<ll>   usll;
//typedef    unordered_multiset<ll>   umsll;
typedef    multiset<ll>   msll;
typedef    set<ll>   sll;
typedef    vector<ll>   vll;
typedef    pair<ll,ll>   pll;
typedef    vector<pll>   vpll;
typedef    priority_queue<ll>   pqll;
typedef    vector<int>   vi;
typedef    set<int>   si;
typedef    multiset<int>   msi;
//typedef    unordered_multiset<int>   umsi;
//typedef    unordered_set<int>   usi;
typedef     pair<int,int>   pi;
typedef    vector<pi>   vpi;
typedef    set<pi>   spi;
typedef    priority_queue<int>   pqi;
typedef    tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>   ind_set;
typedef    tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>   ind_setll;
#define    in   insert
#define    fi   first
#define    se   second
#define    pb   push_back
#define    mp   make_pair
#define    be   begin
#define    en   end
#define    itr   iterator
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define    mo   1000000007
#define    inf  9223372036854775807
#define    ninf   -inf
#define    ima   2147483647
#define    imi   -ima
#define    oncnt    __builtin_popcount
#define    zerobegin   __builtin_clz
#define    zeroend   __builtin_ctz
#define    parity   __builtin_parity
#define    all(x)   x.be(),x.en()
#define    eps   1e-9
#define    coutd   cout<<setprecision(10)<<fixed
#define    mems(dp,x)   memset(dp,x,sizeof(dp))
const    ld   PI=3.14159265359;
inline ll modpow(ll x,ll n){if(n==0)return 1;if(n==1)return(x%mo);ll u=(modpow(x,n/2));u=(u*u)%mo;if(n%2!=0)u=(u*x%mo)%mo;return u;}
inline ll modinv(ll x){return modpow(x,mo-2);}
inline ll mmul(ll a,ll b){    if(a>=mo)a=a%mo;if(b>=mo)b=b%mo;if(a*b>=mo)return(a*b)%mo;return(a*b);}
inline ll madd(ll a, ll b){if(a>=mo)a=a%mo;if(b>=mo)b=b%mo;if(a+b>=mo)return(a+b)%mo;return(a+b);}
inline ll msub(ll a, ll b){if(a>=mo)a=a%mo;if(b>=mo)b=b%mo;return(((a-b)%mo+mo)%mo);}
inline ll mdiv(ll a,ll bb){if(a>=mo)a=a%mo;ll b=modinv(bb);if(b>=mo)b=b%mo;if(a*b>=mo)return(a*b)%mo;return(a*b);}
inline ll gcd(ll a,ll b){return __gcd(a,b);}

ll dp[100001][101][2];
string a;
ll d;
ll call(int pos,int sum,int fa)
{
	if(pos==a.length())
	{
		if(sum==0)
		return 1;
		else
		return 0;
	}
	
	ll &x=dp[pos][sum][fa];
	if(x!=-1)
	return x;
	x=0;
	
	int lm=9;
if(fa==0)
lm=a[pos]-'0';
	
	for(int i=0;i<=lm;i++)
	{
		int nf=fa;
		if(fa==0&&a[pos]-'0'>i) nf=1;
		x=madd(x,call(pos+1,(sum+i)%d,nf));
	}
	return x;
}

int main()
{
io
int testcases=1;//cin>>testcases;
while(testcases--)
{
	mems(dp,-1);
cin>>a>>d;
cout<<msub(call(0,0,0),1);

}return 0;}