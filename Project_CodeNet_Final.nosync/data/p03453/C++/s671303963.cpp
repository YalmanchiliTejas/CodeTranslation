#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define INF (1<<30)
#define INFLL (1ll<<60)
#define MOD (1000000007)
#define MODLL (1000000007ll)
typedef pair<ll, int> PLI;

vector<PLI> g[123456];
ll tkhs[123456],aoki[123456],stot[123456],ttos[123456];


priority_queue< PLI, vector<PLI>, greater<PLI> > pq;

int main(void){
	int n,m,s,t,u,v,i,j,now,next;
	ll d,dist,edge,ans;
	PLI tmp;
	fill(tkhs,tkhs+123456,INFLL);
	fill(aoki,aoki+123456,INFLL);
	fill(stot,stot+123456,0ll);
	fill(ttos,ttos+123456,0ll);
	cin >> n >> m;
	cin >> s >> t;
	s--;
	t--;
	tkhs[s] = 0ll;
	aoki[t] = 0ll;
	stot[s] = 1ll;
	ttos[t] = 1ll;
	for(i=0; i<m; i++){
		cin >> u >> v >> d;
		u--;
		v--;
		g[u].push_back(PLI(d,v));
		g[v].push_back(PLI(d,u));
	}
	pq.push(PLI(tkhs[s],s));
	while(!pq.empty()){
		tmp = pq.top();
		pq.pop();
		now = tmp.second;
		dist = tmp.first;
		for(i=(g[now].size()-1); i>=0; i--){
			next = g[now][i].second;
			edge = g[now][i].first;
			if(tkhs[next] >  dist + edge ){
				tkhs[next] = dist + edge;
				pq.push(PLI(tkhs[next],next));
			}
		}
	}
	for(i=0; i<n; i++){
		pq.push(PLI(tkhs[i],i));
	}
	while(!pq.empty()){
		tmp = pq.top();
		pq.pop();
		now = tmp.second;
		dist = tmp.first;
		for(i=(g[now].size()-1); i>=0; i--){
			next = g[now][i].second;
			edge = g[now][i].first;
			if(tkhs[next] == dist + edge){
				stot[next] += stot[now];
				stot[next] %= MOD;
			}
		}
	}
	pq.push(PLI(aoki[t],t));
	while(!pq.empty()){
		tmp = pq.top();
		pq.pop();
		now = tmp.second;
		dist = tmp.first;
		for(i=(g[now].size()-1); i>=0; i--){
			next = g[now][i].second;
			edge = g[now][i].first;
			if(aoki[next] >  dist + edge ){
				aoki[next] = dist + edge;
				pq.push(PLI(aoki[next],next));
			}
		}
	}
	for(i=0; i<n; i++){
		pq.push(PLI(aoki[i],i));
	}
	while(!pq.empty()){
		tmp = pq.top();
		pq.pop();
		now = tmp.second;
		dist = tmp.first;
		for(i=(g[now].size()-1); i>=0; i--){
			next = g[now][i].second;
			edge = g[now][i].first;
			if(aoki[next] == dist + edge){
				ttos[next] += ttos[now];
				ttos[next] %= MODLL;
			}
		}
	}
	ans = stot[t] * ttos[s];
	ans %= MOD;
	for(i=0; i<n; i++){
		if((tkhs[i] == aoki[i]) && ((tkhs[i] + aoki[i]) == tkhs[t])){
			dist = (stot[i] * ttos[i]) % MOD;
			dist *= dist;
			dist %= MODLL;
			ans -= dist;
			ans += MODLL;
			ans %= MODLL;
		}
		for(j=(g[i].size()-1); j>=0; j--){
			next = g[i][j].second;
			edge = g[i][j].first;
			if(tkhs[i] + edge + aoki[next] != tkhs[t]){
				continue;
			}
			if(tkhs[i] < aoki[i] && aoki[next] < tkhs[next]){
				dist = (stot[i] * ttos[next]) % MOD;
				dist *= dist;
				dist %= MODLL;
				ans -= dist;
				ans += MODLL;
				ans %= MODLL;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
