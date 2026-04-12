#include<iostream>
#include<iomanip>
#include<math.h>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<bitset>
#include<random>
#include<time.h>
#define INF 1000000000ll
#define MOD 1000000007ll
#define EPS 1e-10
#define REP(i,m) for(long long i=0; i<m; i++)
#define FOR(i,n,m) for(long long i=n; i<m; i++)
#define DUMP(a) for(long long dump=0; dump<(ll)a.size(); dump++) { cout<<a[dump]; if(dump!=(ll)a.size()-1) cout<<" "; else cout<<endl; }
#define ALL(v) v.begin(),v.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;

vector<vector<P>> graph;

void dij(ll s, vector<ll>& d, vector<ll>& cnt) {
	d[s]=0;
	cnt[s]=1;
	priority_queue<P,vector<P>,greater<P>> q;
	q.push(P(0,s));
	while(!q.empty()) {
		ll dir=q.top().first;
		ll p=q.top().second;
		q.pop();
		if(d[p]!=dir) continue;
		ll buf=0;
		REP(i,(ll)graph[p].size()) {
			ll np=graph[p][i].first;
			ll cost=graph[p][i].second;
			if(d[np]+cost==d[p]) {
				buf+=cnt[np];
				buf%=MOD;
			}
			if(d[np]>d[p]+cost) {
				d[np]=d[p]+cost;
				q.push(P(d[np],np));
			}
		}
		if(p!=s) cnt[p]=buf;
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n,m,s,t;
	cin>>n>>m>>s>>t;
	s--; t--;
	graph.resize(n);
	REP(i,m) {
		ll u,v,d;
		cin>>u>>v>>d;
		u--;
		v--;
		graph[u].pb(P(v,d));
		graph[v].pb(P(u,d));
	}
	vector<ll> dFromS(n,INF*INF);
	vector<ll> dFromT(n,INF*INF);
	vector<ll> cntFromS(n,0);
	vector<ll> cntFromT(n,0);

	dij(s,dFromS,cntFromS);
	dij(t,dFromT,cntFromT);
	ll diam=dFromS[t];

	ll ans=cntFromS[t]*cntFromS[t];
	ans%=MOD;

	if(diam%2==0) {
		REP(i,n) if(dFromS[i]==diam/2&&dFromS[i]+dFromT[i]==diam) {
			ans-=((cntFromS[i]*cntFromT[i])%MOD)*((cntFromS[i]*cntFromT[i])%MOD);
			ans%=MOD;
		}
	}
	REP(i,n) {
		REP(j,(ll)graph[i].size()) {
			ll a=i,b=graph[i][j].first;
			ll cost=graph[i][j].second;
			if(a>b) continue;
			if(dFromS[a]==dFromS[b]) continue;
			if(dFromS[a]>dFromS[b]) swap(a,b);
			if(dFromS[a]+cost+dFromT[b]==diam&&(dFromS[a]<diam/2&&dFromS[b]>diam/2)) {
				ans-=((cntFromS[a]*cntFromT[b])%MOD)*((cntFromS[a]*cntFromT[b])%MOD);
				ans%=MOD;
			}
		}
	}
	cout<<(ans+MOD)%MOD<<endl;
}
