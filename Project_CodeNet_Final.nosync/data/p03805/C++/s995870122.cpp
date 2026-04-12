#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
using graph = vector<vector<int>>;

#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define repd(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
//xにはvectorなどのコンテナ
#define all(x) (x).begin(),(x).end()
#define size(x) ((ll)(x).size())
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))

#define INF 1000000000000
#define MOD 10000007
#define MAXR 100000

#define pb push_back
#define mp make_pair
#define f first
#define s second

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main(){
	int n,m;cin>>n>>m;
	graph g(n);
	rep(i,m){
		int a,b;cin>>a>>b;
		a--;
		b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	int ans=0;
	vector<int> v(n);
	rep(i,n)v[i]=i;
	rep(i,n-1){
		if(find(all(g[v[i]]),v[i+1])==g[v[i]].end()&&find(all(g[v[i+1]]),v[i])==g[v[i+1]].end())break;
		if(i==n-2)ans++;
	}
	while(next_permutation(all(v))){
		if(v[0]!=0)continue;
		rep(i,n-1){
			if(find(all(g[v[i]]),v[i+1])==g[v[i]].end()&&find(all(g[v[i+1]]),v[i])==g[v[i+1]].end())break;
			if(i==n-2)ans++;
		}
	}
	cout<<ans<<endl;
}

