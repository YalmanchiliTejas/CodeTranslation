
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;
using ll = long long;
using ull = unsigned long long;
#define out(S) cout<<(S)<<endl;
#define REP(i,b) for(size_t i=0;i<(b);i++)
#define rREP(i,b) for(size_t i=(b)-1;i>=0;i--)
#define FOR(i,a,b) for(size_t i=(a);i<(b);i++)
#define rFOR(i,a,b) for(size_t i=(b)-1;i>=0;i--)
#define Foreach(item,collection) for(auto item:collection)
#define mod(i) ((i) % (ll)(1e9 + 7))
ll modpow(ll i, ll j) { ll tmp = 1; while (j) { if (j % 2)tmp = mod(tmp*i); i = mod(i*i); j /= 2; }return tmp; }
#define divmod(a,b) (mod(a * modpow((ll)b,(ll)(1e9 + 5))))

bool check(vector<int> v) {
	int tmp = 0;
	Foreach(item, v) {
		if (tmp == item) return false;
		tmp = item;
	}
	return true;
}

int N, M;
vector<int> graph[10];
int ans = 0;

int dfs(int current, vector<bool> used) {
	if (used[current])return 0;
	used[current] = true;
	bool all = true;
	REP(i, N + 1) if (!used[i]) { all = false; break; }
	if (all) return 1;
	Foreach(item, graph[current]) {
		ans += dfs(item, used);
	}
	return 0;
}

int main(){
	cin >> N >> M;
	REP(i, M) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	vector<bool> used(N + 1, false);
	used[0] = true;
	dfs(1, used);
	out(ans);
}

