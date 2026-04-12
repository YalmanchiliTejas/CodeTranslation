#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
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
#ifdef leowang
#define debug(...) do{\
	fprintf(stderr,"%s - %d : (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
	_DO(__VA_ARGS__);\
}while(0)
template<typename I> void _DO(I&&x){cerr<<x<<endl;}
template<typename I,typename...T> void _DO(I&&x,T&&...tail){cerr<<x<<", ";_DO(tail...);}
#else
#define debug(...)
#endif
template<typename T1,typename T2>
ostream& operator<<(ostream& out,pair<T1,T2> P){
	out<<'('<<P.F<<','<<P.S<<')';
	return out;
}
//}}}
const ll maxn=300005;
const ll maxlg=__lg(maxn)+2;
const ll INF64=8000000000000000000LL;
const int INF=2000000000;
const ll MOD=ll(1e9+7);
const double PI=acos(-1);
//const ll p=880301;
//const ll P=31;
/*
ll mypow(ll a,ll b){
	ll res=1LL;
	while(b){
		if(b&1) res=res*a%MOD;
		else a=a*a%MOD;
		b>>=1;
	}
	return res;
}
*/
int n;
ll a[maxn];
ll b[maxn];

int main()
{
	IOS;
	cin>>n;
	REP(i,n) cin>>a[i];

	ll sum=0;
	REP(i,n) sum+=a[i];

	ll meow=INF64;
	for(int i=0;i<=n;i++){
		REP(j,n) b[j]=(a[j]+i)%(n+1);
		REP(j,n) if(b[j]==n) b[j]-=n+1;
		
		ll step=sum;
		REP(j,n) step-=b[j];

		REP(i,n){
			if(b[i]>a[i]+step) b[i]-=n+1;
		}
		step=sum;
		REP(j,n) step-=b[j]; 
		meow=min(meow,step);
	}
	cout<<meow;
	return 0;
}
