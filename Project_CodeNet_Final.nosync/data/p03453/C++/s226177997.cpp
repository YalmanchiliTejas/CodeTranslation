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

int n, m;
vector<pp> edge[200010];

int S, T;

ll d[2][200010];
ll w[2][200010];
ll rw[2][200010];
bool re[2][200010];

priority_queue<pair<ll,int>> pq;
int order[100010];

const ll mod = 1'000'000'007, inf = 1ll<<60;

void Work(int S, ll *d, ll *w, ll *rw, bool *re){
	int T=::S+::T-S;
	for(int i=1; i<=n; ++i) d[i]=inf; d[S]=0; pq.emplace(0, S); w[S] = 1;
	int on = 0;
	while(pq.size()){
		int p; ll md; tie(md, p)=pq.top(); pq.pop();
		if(md != -d[p]) continue;
		order[on++] = p;
		for(auto tmp:edge[p]){
			int y, e; tie(y, e) = tmp;
			if(d[y]>e-md){
				d[y]=e-md;
				w[y]=w[p];
				pq.emplace(-d[y], y);
			} else if(d[y]==e-md){
				(w[y]+=w[p]) %= mod;
			}
		}
	}
	rw[T]=1; re[T]=1;
	for(int i=on-1; 0<=i; --i){
		int p=order[i];
		if(!re[p]) continue;
		for(auto tmp:edge[p]){
			int q, e; tie(q, e) = tmp;
			if(d[q] == d[p]-e){
				(rw[q] += rw[p]) %= mod;
				re[q]=1;
			}
		}
	}
}

bool intersect(ll a, ll b, ll c, ll d){
	return min(b, d)-max(a, c)>=1;
}

int main()
{
	read(n, m, S, T);
	for(int i=1; i<=m; ++i){
		int a, b, c; read(a, b, c);
		edge[a].eb(b, c); edge[b].eb(a, c);
	}
	Work(S, d[0], w[0], rw[0], re[0]);
	Work(T, d[1], w[1], rw[1], re[1]);
	
	ll ans = 0;
	
	for(int i=1; i<=n; ++i){
		for(auto tmp:edge[i]){
			int j, e;
			tie(j, e) = tmp;
			if(d[0][j]==d[0][i]+e && re[0][i] && re[0][j] &&
			   d[1][i]==d[1][j]+e && re[1][i] && re[1][j]){
				if(intersect(d[0][i], d[0][j], d[1][j], d[1][i])){
					(ans += w[0][i] * w[1][j] % mod * rw[0][j] % mod * rw[1][i] % mod) %= mod;
				}
			}
		}
		if(d[0][i] == d[1][i]){
			(ans += w[0][i] * w[1][i] % mod * rw[0][i] % mod * rw[1][i] % mod) %= mod;
		}
	}
	
	printf("%lld\n", ((w[0][T]*w[1][S]%mod-ans)%mod+mod)%mod);
	return 0;
}
