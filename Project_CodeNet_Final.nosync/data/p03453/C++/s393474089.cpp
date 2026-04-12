#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<deque>
#include<functional>
#include<ctime>
#include<cassert>
#include<cstring>
using namespace std;

#define sz(x) (int)(x.size())
#define fi(a,b) for(int i=a;i<b;++i)
#define fj(a,b) for(int j=a;j<b;++j)
#define fo(a,b) for(int o=a;o<b;++o)
#define fdi(a,b) for(int i=a-1;i>=b;--i)
#define fdj(a,b) for(int j=a-1;j>=b;--j)
#define fdo(a,b) for(int o=a-1;o>=b;--o)
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;
typedef vector<int> vi;

template<class T> bool uin(T &a, T b){ return (a > b ? a = b, true : false); }
template<class T> bool uax(T &a, T b){ return (a < b ? a = b, true : false); }

/////////////////////////////////

int const N = 1e5 + 41;
int const M = 2e5 + 41;
int const MOD = 1e9 + 7;
ll const INF = 1e18 + 41;

vector<pll> e[N];
int s, t;
pair<ll, int> ds[N], dt[N];
int n, m;

void add(int &a, int b){
	a += b;
	while(a >= MOD) a -= MOD;
	while(a < 0) a += MOD;
}

int mul(int a, int b){
	return (int)( (ll) a * b % MOD );
}

void dijk(int s, pair<ll, int> d[N]){
	int w[N];
	memset(w, 0, sizeof(w));
	fi(0, n) d[i] = mp(INF, 0);
	d[s] = mp(0ll, 1);
	set<pair<ll, int>> t;
	t.insert(mp(0ll, s));
	while(sz(t)){
		pair<ll, int> p = (*t.begin());
		int x = p.second;
		ll dx = p.first;
		t.erase(p);
		if(w[x]) continue;
		w[x] = 1;
		for(pair<ll, ll> edge : e[x]){
			int y = (int)edge.first;
			ll nd = dx + edge.second;
			if(nd == d[y].first){
				add(d[y].second, d[x].second);
			}else if(nd < d[y].first){
				d[y] = mp(nd, d[x].second);
				t.insert(mp(nd, y));
			}
		}
	}
}

int main(){
#ifdef LOCAL_DEFINE
	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
#endif

	scanf("%d %d",&n,&m);
	scanf("%d %d",&s,&t);
	--s;--t;
	fi(0, m){
		int x, y;
		ll z;
		scanf("%d %d %I64d",&x,&y,&z);
		--x;--y;
		e[x].pb(mp(y, z));
		e[y].pb(mp(x, z));
	}		
	dijk(s, ds);
	dijk(t, dt);
	//cerr << ds[t].first << " " << ds[t].second << endl;
		//cerr << dt[s].first << " " << dt[s].second << endl;
	/*
	fi(0, n){
	  cerr << i << " " << ds[i].first << " " << ds[i].second << endl;
	}
	fi(0, n){
	  cerr << i << " " << dt[i].first << " " << dt[i].second << endl;
	} */



	int ans = mul(ds[t].second, ds[t].second);
	fi(0, n){
		if(ds[i].first == dt[i].first){
			int v0 = ds[i].second;
			v0 = mul(v0, v0);
			int v1 = dt[i].second;
			v1 = mul(v1, v1);
			int v = mul(v0, v1);
			add(ans, -v);
		}
	}
	ll md = ds[t].first;
	fi(0, n){
		for(pair<ll, ll> edge : e[i]){
			int x = i;
			int y = (int)edge.first;
			ll c = edge.second;
			if(x > y) continue;
			if(ds[x].first > ds[y].first) swap(x, y);			
			if(ds[x].first + c + dt[y].first > md) continue;
			ll x0 = min(ds[x].first, dt[y].first);
			ll x1 = max(ds[x].first, dt[y].first);
			if(!(x0 + c > x1)) continue;
			int v0 = ds[x].second;
			v0 = mul(v0, v0);
			int v1 = dt[y].second;
			v1 = mul(v1, v1);
			int v = mul(v0, v1);
//			if(v != 0) cerr << x << " " << y <<  " " << v << endl;
			add(ans, -v);
		}
	}

	printf("%d\n",ans);
	
#ifdef LOCAL_DEFINE
	fprintf(stderr, "ELAPSED TIME: %.3lf\n", (ld) clock() / CLOCKS_PER_SEC);
#endif	
	
	return 0;
}