#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll N,M,S,T,U[200010],W[200010],D[200010],inf = 1e9+7;
vector<vector<P>> v(100010);
ll C[100010];

int main(){
	cin >> N >> M >> S >> T;
	for(int i=0;i<M;i++){
		cin >> U[i] >> W[i] >> D[i];
		v[U[i]].push_back({D[i],W[i]});
		v[W[i]].push_back({D[i],U[i]});
	}
	priority_queue<P> Q;
	Q.push(P(0,S));
	for(int i=1;i<=N;i++) C[i] = 1e18;
	C[S] = 0;
	while(!Q.empty()){
		P t = Q.top();
		ll s = t.second;
		Q.pop();
		if(C[s] > -t.first) continue;
		for(int i=0;i<v[s].size();i++){
			P e = v[s][i];
			if(C[e.second] > C[s] + e.first){
				C[e.second] = C[s] + e.first;
				Q.push(make_pair(-C[e.second],e.second));
			}
		}
	}
	ll dp1[N+1] = {0};
	int visited[N+1] = {0};	
	dp1[S] = 1;
	visited[S] = 1;
	Q.push({-C[S],S});
	while(!Q.empty()){
		P a = Q.top();
		ll s = a.second;Q.pop();
		for(int i=0;i<v[s].size();i++){
			ll t = v[s][i].second;
			if(C[s]+v[s][i].first==C[t]){
				dp1[t] += dp1[s];
				dp1[t] %= inf;
				if(visited[t]==0){
					Q.push({-C[t],t});
					visited[t] = 1;
				}
			}
		}
	}
	for(int i=0;i<=N;i++) visited[i] = 0;
	ll dp2[N+1] = {0};
	dp2[T] = 1;
	visited[T] = 1;
	Q.push({C[T],T});
	while(!Q.empty()){
		P a = Q.top();
		ll s = a.second;Q.pop();
		for(int i=0;i<v[s].size();i++){
			ll t = v[s][i].second;
			if(C[s]-v[s][i].first==C[t]){
				dp2[t] += dp2[s];
				dp2[t] %= inf;
				if(visited[t]==0){
					Q.push({C[t],t});
					visited[t] = 1;
				}
			}
		}
	}
	ll ans = (dp1[T]*dp1[T])%inf;
	for(int i=1;i<=N;i++){
		if(2*C[i]==C[T]){
			ll a = (dp1[i]*dp1[i])%inf,b = (dp2[i]*dp2[i])%inf;
			ans -= (a*b)%inf;
			ans = (ans+inf)%inf;
		}
	}
	for(int i=0;i<M;i++){
		if(2*C[U[i]]<C[T] && 2*C[W[i]]>C[T] && C[U[i]]+D[i]==C[W[i]]){
			ll a = (dp1[U[i]]*dp1[U[i]])%inf,b = (dp2[W[i]]*dp2[W[i]])%inf;
			ans -= (a*b)%inf;
			ans = (ans+inf)%inf;	
		}
		if(2*C[W[i]]<C[T] && 2*C[U[i]]>C[T] && C[W[i]]+D[i]==C[U[i]]){
			ll a = (dp1[W[i]]*dp1[W[i]])%inf,b = (dp2[U[i]]*dp2[U[i]])%inf;
			ans -= (a*b)%inf;
			ans = (ans+inf)%inf;	
		}
	}
	cout << ans << endl;
}