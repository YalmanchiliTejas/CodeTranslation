/*input
4
1 2
2 3
2 4
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

vector<int> edge[maxn];
int deg[maxn];

set<pii> st;
bool vis[maxn];
int main()
{
	IOS;
	int n;
	cin>>n;
	REP(i,n-1){
		int u,v;
		cin>>u>>v;
		u--;v--;
		edge[u].pb(v);
		edge[v].pb(u);
	}
	REP(i,n) deg[i]=SZ(edge[i]);

	REP(i,n) st.insert(MP(deg[i],i));

	while(SZ(st)){
		pii cur=*st.begin();
		vis[cur.S]=1;
		//cout<<cur<<'\n';
		if(deg[cur.S]!=1){
			cout<<"First\n";
			return 0;
		}
		st.erase(st.begin());
		int ptr=-1;
		for(int v:edge[cur.S]) if(!vis[v]) ptr=v;
			//cout<<ptr<<'\n';
		vis[ptr]=1;
		for(int v:edge[ptr]) if(!vis[v]){
			st.erase(MP(deg[v],v));
			deg[v]--;
			st.insert(MP(deg[v],v));
		}
		st.erase(MP(deg[ptr],ptr));
	}
	cout<<"Second\n";
	return 0;
}
