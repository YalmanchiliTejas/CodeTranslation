#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#define int long long
using namespace std;
typedef pair<int, int> P;

int mod = 1000000007;
int INF = 1e+15;
int n, m;
int s, t;
int u[200000], v[200000], d[200000];
vector<int> et[100000];
vector<int> ec[100000];
int minS[100000];
int minT[100000];
int cntS[100000];
int cntT[100000];
int cntS2[100000];
int cntT2[100000];

void setMinDist(int minD[], int start) {
	int i;
	priority_queue<P, vector<P>, greater<P> > que;
	
	for (i = 0; i < n; i++) minD[i] = INF;
	que.push(P(0, start));
	minD[start] = 0;
	
	while (!que.empty()) {
		P now = que.top(); que.pop();
		int cst = now.first;
		int pos = now.second;
		for (i = 0; i < et[pos].size(); i++) {
			int npos = et[pos][i];
			if (minD[npos] > minD[pos] + ec[pos][i]) {
				minD[npos] = minD[pos] + ec[pos][i];
				que.push(P(minD[npos], npos));
			}
		}
	}
}

//ここにバグがある！！！
void setWayCnt(int minD[], int cntD[], int start) {
	int i, j;
	priority_queue<P, vector<P>, greater<P> > que;
	static vector<bool> used[100000];
	//static bool pushed[100000];
	
	for (i = 0; i < n; i++) {
		used[i].resize(et[i].size());
		for (j = 0; j < et[i].size(); j++) {
			used[i][j] = false;
		}
		//pushed[i] = false;
	}
	
	for (i = 0; i < n; i++) cntD[i] = 0;
	
	que.push(P(0, start));
	cntD[start] = 1;
	//pushed[start] = true;
	while (!que.empty()) {
		P now = que.top(); que.pop();
		int cst = now.first;
		int pos = now.second;
		for (i = 0; i < et[pos].size(); i++) {
			int npos = et[pos][i];
			if (minD[npos] != minD[pos] + ec[pos][i]) continue;
			if (used[pos][i]) continue;
			used[pos][i] = true;
			//cout << "add <=" << npos + 1<< "<- " << pos +1 << "| " << cntD[pos] << endl;
			cntD[npos] += cntD[pos];
			cntD[npos] %= mod;
			/*if (!pushed[npos])*/ que.push(P(minD[npos], npos));
		}
	}
}

signed main() {
	int i;
	
	cin >> n >> m >> s >> t;
	s--; t--;
	for (i = 0; i < m; i++) {
		cin >> u[i] >> v[i] >> d[i];
		u[i]--; v[i]--;
		et[u[i]].push_back(v[i]);
		et[v[i]].push_back(u[i]);
		ec[u[i]].push_back(d[i]);
		ec[v[i]].push_back(d[i]);
	}
	
	setMinDist(minS, s);
	setMinDist(minT, t);
	setWayCnt(minS, cntS, s);
	//cout << "T" << endl;
	setWayCnt(minT, cntT, t);
	
	int X = minS[t];
	int crash = 0;
	
	for (i = 0; i < n; i++) {
		cntS2[i] = (cntS[i] * cntS[i]) % mod;
		cntT2[i] = (cntT[i] * cntT[i]) % mod;
	}
	
	//頂点
	for (i = 0; i < n; i++) {
		if (minS[i] + minT[i] > X) continue;
		if (minS[i] != minT[i]) continue;
		crash += cntS2[i] * cntT2[i];
		crash %= mod;
	
	}
	
	//cout << crash << endl;
	
	//辺
	for (i = 0; i < m; i++) {
		//cout << minS[u[i]] + minT[u[i]] << endl;
		if (minS[u[i]] > minS[v[i]]) swap(u[i], v[i]);
		if (minS[u[i]] + d[i] + minT[v[i]] > X) continue;
		if (minS[u[i]] >= (X + 1) / 2) continue;
		if (minT[v[i]] >= (X + 1) / 2) continue;
		//cout << "crash(u, v) = " << u[i] << ", " << v[i] << endl;
		crash += cntS2[u[i]] * cntT2[v[i]];
		crash %= mod;
	}
	
	//cout << crash << endl;
	
	//答え
	int ans = cntS[t] * cntT[s];
	ans %= mod;
	ans = (ans + mod - crash) % mod;
	cout << ans << endl;
	return 0;
}