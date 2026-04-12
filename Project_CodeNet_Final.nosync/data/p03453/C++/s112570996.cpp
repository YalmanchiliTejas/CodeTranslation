///A drunk man will find his way home, but a drunk bird may get lost forever...
#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef pair <int, int> pii;
#define pb push_back
#define f first
#define s second
#define sz(x) (int)x.size()
const int mx = 1000 * 100 + 5, M = 1e9 + 7;
int n, m, s, t, dis[2][mx], cnt[2][mx];
set < pii > ms;
vector < pii > ad[mx];
vector < pair < pii , int > > ed;
void dij(int a, int ind){
	memset(dis[ind], 127, sizeof dis[ind]);
	dis[ind][a] = 0;
	cnt[ind][a] = 1;
	for(int i = 0; i < n; i++)
		ms.insert({dis[ind][i], i});
	while(sz(ms)){
		auto v = ms.begin() -> s;
		ms.erase(ms.begin());
		for(auto u : ad[v]){
			if(dis[ind][v] + u.s < dis[ind][u.f]){
				ms.erase({dis[ind][u.f] , u.f});
				dis[ind][u.f] = dis[ind][v] + u.s;
			//	cnt[ind][u.f] = 0;
				cnt[ind][u.f] = cnt[ind][v];
				ms.insert({dis[ind][u.f] , u.f});
			}
			else if(dis[ind][v] + u.s == dis[ind][u.f]){
				cnt[ind][u.f] += cnt[ind][v];
				(cnt[ind][u.f] >= M ? cnt[ind][u.f] -= M : cnt[ind][u.f] = cnt[ind][u.f]);
			}
		}
	}
	return;
}
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
 	cout.tie(0);
	cin >> n >> m >> s >> t;
	s--, t--;
	int u, v, w;
	for(int i = 0; i < m; i++){
		cin >> u >> v >> w;
		u--, v--;
		ad[u].pb({v , w});
		ad[v].pb({u , w});
		ed.pb({{u , v} , w});
	}
	dij(s , 0);
//	cnt[0][s] = 0;
//	cout << cnt[0][t] << endl;
//	for(int i = 0; i < n; i++)
//		cout << i + 1 << " " << cnt[0][i] << endl;
	dij(t , 1);
//	cnt[1][t] = 0;
//	cout << cnt[1][s] << endl;
	int sum = cnt[0][t] * cnt[1][s] % M;
	for(int i = 0; i < n; i++){
		if(dis[0][i] == dis[1][i] && dis[0][i] + dis[1][i] == dis[0][t]){
			sum += M - cnt[0][i] * cnt[0][i] % M * cnt[1][i] % M * cnt[1][i] % M;
			(sum >= M ? sum -= M : sum = sum);
		}
	}
//	cout << sum << endl;
	for(auto u : ed){
		if (dis[0][u.f.f] > dis[0][u.f.s]) 
			swap(u.f.f , u.f.s);
	//	cout << u.f.f + 1 << " " << u.f.s + 1 << " " << dis[0][u.f.f] << " " << dis[1][u.f.s] << " " << u.s << " " << dis[1][s] << endl;
		if(dis[0][u.f.f] + dis[1][u.f.s] + u.s == dis[1][s] && dis[0][u.f.f] < dis[1][s] / 2 && dis[1][u.f.s] < dis[1][s] / 2){
		//	cout << "aejhgh" << endl;
		//	cout << u.f.f << " " << u.f.s << endl;
		//	cout << cnt[0][u.f.f] << " " << cnt[1][u.f.s] << endl;
			sum += M - cnt[0][u.f.f] * cnt[0][u.f.f] % M * cnt[1][u.f.s] % M * cnt[1][u.f.s] % M;
			(sum >= M ? sum -= M : sum = sum);

		}
	}
	cout << sum << endl;
	return 0;
}

