#include <bits/stdc++.h>

#define rep(i,n) for(int i=0; i<(n); i++)
#define reps(i,x,n) for(int i=x; i<(n); i++)
#define rrep(i,n) for(int i=(n)-1; i>=0; i--)
#define all(X) (X).begin(),(X).end()
#define X first
#define Y second
#define pb push_back
#define eb emplace_back

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

template<class A, size_t N, class T> void Fill(A (&a)[N], const T &v){ fill( (T*)a, (T*)(a+N), v ); }

const ll INF = 1e17+7;
const ll MOD = 1e9+7;

typedef pair<ll,pll> P;


int main(){
	ios_base::sync_with_stdio(false);
	int N, M;
	int S[2];
	vector<pll> edge[100005];
	vector<P> eg;

	cin >> N >> M;
	rep(k,2){
		cin >> S[k];
		S[k]--;
	}
	rep(i,M){
		int u, v, d;
		cin >> u >> v >> d;
		u--; v--;
		edge[u].emplace_back(v, d);
		edge[v].emplace_back(u, d);
		eg.emplace_back(u, pll(v, d));
	}

	ll D[2][100005];
	ll sum[2][100005]={};
	Fill(D, INF);
	vector<int> from[100005];
	rep(k,2){
		//sum[k][S[k]] = 1;
		priority_queue<P, vector<P>, greater<P>> que;
		que.emplace(0, pll(S[k],-1));
		D[k][S[k]] = 0;
		while(!que.empty()){
			ll d = que.top().X;
			ll n = que.top().Y.X;
			ll s = que.top().Y.Y;
			que.pop();
			if( d > D[k][n] ) continue;
			if( s < 0 ) sum[k][n] += 1;
			else        sum[k][n] += sum[k][s];
			sum[k][n] %= MOD;
			if(k == 0) from[n].push_back(s);
			if( !que.empty() && que.top().X == D[k][n] && que.top().Y.X == n ) continue;
			for(auto p: edge[n]){
				if( D[k][p.X] >= D[k][n] + p.Y ){
					D[k][p.X] = D[k][n] + p.Y;
					que.emplace(D[k][p.X], pll(p.X, n));
				}
			}
		}
	}
	// rep(i,N) cout << D[0][i] << " "; cout << endl;
	// rep(i,N) cout << D[1][i] << " "; cout << endl;
	// rep(i,N) cout << sum[0][i] << " "; cout << endl;
	// rep(i,N) cout << sum[1][i] << " "; cout << endl;
	ll len = D[0][S[1]];
	ll ans = (sum[0][S[1]] * sum[1][S[0]]) % MOD;
	//cout << "ans: " << ans << endl;
	queue<int> Q;
	Q.push(S[1]);
	set<int> used;
	while(!Q.empty()){
		int n = Q.front();
		Q.pop();
		if( used.count(n) ) continue;
		used.insert(n);
		if( D[0][n] == D[1][n] && D[0][n] * 2ll == len ){
			ll u2 = (sum[0][n] * sum[0][n]) % MOD;
			ll v2 = (sum[1][n] * sum[1][n]) % MOD;
			ll s = (u2 * v2) % MOD;
			ans = (ans + MOD - s) % MOD;
		}
		for(auto t: from[n]){
			int u = n;
			int v = t;
			Q.push(t);
			//int v = p.Y.X;
			// int d = p.Y.Y;
			// if( D[0][u] + D[1][u] != len ) continue;
			// if( D[0][v] + D[1][v] != len ) continue;
			// if( abs(D[0][u] - D[0][v]) != d ) continue;
			// if( abs(D[1][u] - D[1][v]) != d ) continue;
			bool f = false;
			// if( D[0][u] == D[1][u] ) f = true;
			// if( D[0][v] == D[1][v] ) f = true;
			if( D[0][u] > D[1][u] && D[0][v] < D[1][v] ) f = true;
			if( D[0][u] < D[1][u] && D[0][v] > D[1][v] ) f = true;
			if( !f ) continue;
			if( D[0][u] > D[0][v] && D[1][u] < D[1][v] ) swap(u, v);
			if( D[0][v] == D[1][v] ) continue;
			ll s = 0;
			if( D[0][u] < D[0][v] && D[1][u] > D[1][v] ){
				ll u2 = (sum[0][u] * sum[0][u]) % MOD;
				ll v2 = (sum[1][v] * sum[1][v]) % MOD;
				s = (u2 * v2) % MOD;
			}
			// if( D[0][u] > D[0][v] && D[1][u] < D[1][v] ){
			// 	s = (sum[0][v] * sum[1][u]) % MOD;
			// }
			//if(s) cout << "u:" << u << " v:" << v << " " << s << endl;
			ans = (ans + MOD - s) % MOD;
		}
	}

	cout << ans << endl;

	return 0;
}
