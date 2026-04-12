/*input
4 5
##...
.###.
.###.
...##
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
const ll maxn=300005;
const ll maxlg=__lg(maxn)+2;
const ll INF64=8000000000000000000LL;
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
string s[10];
vector<pii> v;
bool cmp(pii a,pii b){
	return a.F+a.S<b.F+b.S;
}
int main()
{
	IOS;
	int n,m;
	cin>>n>>m;
	REP(i,n) cin>>s[i];
	REP(i,n) REP(j,m){
		if(s[i][j]=='#') v.pb(MP(i,j));
	}
	sort(ALL(v));

	for(int i=0;i<SZ(v)-1;i++){
		if(v[i].F+v[i].S==v[i+1].F+v[i+1].S-1&&(v[i].F==v[i+1].F||v[i].S==v[i+1].S));
		else{
			cout<<"Impossible\n";
			return 0;
		}
	}
	cout<<"Possible\n";
	return 0;
}
