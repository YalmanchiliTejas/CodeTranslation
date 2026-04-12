#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#ifdef ONLINE_JUDGE
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
#define fu(a,b,c) for(int a=b;a<=(int)c;++a)
#define fd(a,b,c) for(int a=b;a>=(int)c;--a)
#define cu(a,b,c) for(int a=b;a<(int)c;++a)
#define cd(a,b,c) for(int a=(b)-1;a>=(int)c;--a)
#define gcd(a,b) __gcd(a,b) 
#define pii pair<int,int>
#define pll pair<long long,long long>
#define all(a) a.begin(),a.end()
#define F first
#define S second
#define pb push_back
#define pf push_front
#define uint unsigned int
#define MOD 1000000007
#define MAXN 5000
#define MAXH 4
#define MAXM 4
#define INF 1LL << 60
#define ll long long
#define ull unsigned long long
#define RNG rng mt19937(time(NULL))
#define udist(a,b) uniform_int_distribution<uint32_t> distribution(a,b)
#define max3(a,b,c) max(a, max(b, c))
#define min3(a,b,c) min(a, min(b, c))
#define gmax(a,b) a = max(a, b)
#define gmin(a,b) a = min(a, b)
#define whatis(x) cerr << #x << " is " << x << endl;
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.1415926535897932384626433
using namespace std;
const int N = 100005;
int par[N],rnk[N];

void init(int n){
	for(int i = 0; i < n; ++i){
		par[i] = i;
	}
}

int find_par(int x){
	return (par[x] == x?x:par[x] = find_par(par[x]));
}

void unite(int x,int y){
	x = find_par(x);
	y = find_par(y);
	if(x != y){
		if(rnk[x] > rnk[y]){
			par[y] = x;
		}
		else{
			par[x] = y;
			rnk[y] = max(rnk[y], rnk[x] + 1);
		}
	}
}

vector<pair<ll,pll>> edges;

int main(){
	fast_io();
	int n;
	cin >> n;
	vector<pair<pii,int>> v(n);
	cu(i,0,n){
		cin >> v[i].F.F >> v[i].F.S;
		v[i].S = i;
	}
	init(n);
	cu(cnt,0,2){
		sort(all(v));
		cu(i,0,n-1){
			edges.pb({v[i+1].F.F - v[i].F.F, {v[i].S ,  v[i+1].S}});
			swap(v[i].F.S, v[i].F.F);
		}
		swap(v[n-1].F.S, v[n-1].F.F);
	}
	sort(all(edges));
	ll ans = 0;
	cu(i,0,edges.size()){
		int fst = edges[i].S.F;
		int sec = edges[i].S.S;
		if(find_par(fst) != find_par(sec)){
			ans+=edges[i].F;	
			unite(fst,sec);
		}
	}
	cout << ans << '\n';
}
