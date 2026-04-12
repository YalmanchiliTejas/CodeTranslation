#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> pll;
void read(int& x){ scanf("%d",&x); }
void read(ll& x){ scanf("%lld",&x); }
template<typename T,typename... Args>
void read(T& a,Args&... b){ read(a); read(b...); }
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
#define x first
#define y second

int par[100010];
int r(int x){ return (x==par[x])?x:(par[x]=r(par[x])); }
void join(int a, int b){ par[r(a)]=r(b); }

int n;
pp d[100010];
map<int,vector<int>> xp, yp;

typedef tuple<int,int,int> t3;

int main()
{
	read(n);
	for(int i=1; i<=n; ++i) read(d[i].x, d[i].y), xp[d[i].x].pb(i), yp[d[i].y].pb(i);
	
	for(int i=1; i<=n; ++i) par[i]=i;
	ll ans=0;
	
	vector<t3> asdf;
	int bc, bv;
	bc=-1; bv=-1;
	for(auto& tmp:xp){
		auto& v=tmp.second;
		int n=v.size();
		for(int i=1; i<n; ++i) join(v[i-1], v[i]);
		if(bc >= 0){
			int df=tmp.x-bc;
			asdf.eb(df, bv, v[0]);
		}
		bc=tmp.x; bv=v[0];
	}
	
	bc=-1; bv=-1;
	for(auto& tmp:yp){
		auto& v=tmp.second;
		int n=v.size();
		for(int i=1; i<n; ++i) join(v[i-1], v[i]);
		if(bc >= 0){
			int df=tmp.x-bc;
			asdf.eb(df, bv, v[0]);
		}
		bc=tmp.x; bv=v[0];
	}
	
	sort(all(asdf));
	for(auto tmp:asdf){
		int d, a, b;
		tie(d, a, b) = tmp;
		if(r(a) != r(b)){
			ans += d;
			join(a, b);
		}
	}
	
	printf("%lld\n", ans);
	return 0;
}
