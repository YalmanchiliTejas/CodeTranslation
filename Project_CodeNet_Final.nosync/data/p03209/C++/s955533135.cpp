/*input
50 4321098765432109
*/
#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define ALL(a) a.begin(),a.end()
#define SZ(a) ((int)a.size())
#define F first
#define S second
#define REP(i,n) for(int i=0;i<((int)n);i++)
#define pb push_back
#define MP(a,b) make_pair(a,b)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
template<typename T1,typename T2>
ostream& operator<<(ostream& out,pair<T1,T2> P){
	out<<'('<<P.F<<','<<P.S<<')';
	return out;
}

//}}}
const ll maxn=55;
const ll maxlg=__lg(maxn)+2;
const ll INF64=80000000000000000LL;
const int INF=0x3f3f3f3f;
const ll MOD=ll(1e9+7);
const double PI=acos(-1);
//const ll p=880301;
//const ll P=31;

ll mypow(ll a,ll b){
	ll res=1LL;
	while(b){
		if(b&1) res=res*a%MOD;
		a=a*a%MOD;
		
		b>>=1;
	}
	return res;
}

ll num[maxn];
ll tt[maxn];

ll f(int n,ll x){
	//cout<<n<<' '<<x<<' '<<tt[n]<<'\n';
	if(x==0) return 0;
	if(n==0) return 1;
	if(x==1) return 0;
	if(x<=tt[n-1]+1) return f(n-1,x-1);
	else if(x==tt[n-1]+2) return 1+f(n-1,x-2);
	else if(x==tt[n]) return 1+2*f(n-1,tt[n-1]);
	else return 1+num[n-1]+f(n-1,x-2-tt[n-1]);
}

int main()
{
	IOS;
	num[0]=1;
	for(int i=1;i<maxn;i++) num[i]=num[i-1]*2+1;
	tt[0]=1;
	for(int i=1;i<maxn;i++) tt[i]=tt[i-1]*2+3;

	ll n,x;
	cin>>n>>x;
	cout<<f(n,x)<<'\n';
	return 0;
}
