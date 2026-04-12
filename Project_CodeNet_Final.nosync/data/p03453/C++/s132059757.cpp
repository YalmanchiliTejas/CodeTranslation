#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<utility>
#include<algorithm>
using namespace std;
#define ll long long
#define vel vector<ll>
#define vvel vector<vel>
#define vvvel vector<vvel>
#define veb vector<bool>
#define pin pair<int,int>
#define mkp make_pair
#define mot pair<D,D>//time,dist
#define root pair<int,mot>
#define path pair<ll,int>//cost,to
#define int long long
using namespace std;
vvel ta_min(0);
vvel ta_max(0);
int leth = 1024 * 512;
int siz = leth * 2;
int p = 1000000007;
void mmax(ll &a, ll b) { a = max(a, b); }
void mmin(ll &a, ll b) { a = min(a, b); }
vel dij(int s, vector<vector<path>> &way) {
	int n = way.size();
	int x = 1000 * 1000 * 1000;
	int INF = n * x + 1;
	vel tim(n, INF); tim[s] = 0;
	priority_queue<path> q;
	q.push(mkp(-0,s));
	veb seen(n,false);
	while (!q.empty()) {
		path tp = q.top(); q.pop();
		tp.first *= -1;
		int num = tp.second;
		if (!seen[num]) {
			tim[num] = tp.first;
			seen[num] = true;
			for (int i = 0; i < way[num].size(); i++) {
				path nex = way[num][i];
				path add = mkp(nex.first + tp.first, nex.second);
				add.first *= -1;
				q.push(add);
			}
		}
	}
	return tim;
}
void ref(int &x) { x = x % p; x = (x + p) % p; }
signed main() {
	int n, m; cin >> n >> m;
	int s, t; cin >> s >> t; s--; t--;
	vector<vector<path>> way(n);
	for (int i = 0; i < m; i++) {
		int u, v, d; cin >> u >> v >> d;
		u--; v--;
		way[u].push_back(mkp(d, v));
		way[v].push_back(mkp(d, u));
	}
	vel ti_s = dij(s, way);
	vel ti_t = dij(t, way);
	int dist = ti_s[t];
	vvel can_move_s(n);
	vvel can_move_t = can_move_s;
	vel goal_s(0);
	vel goal_t(0);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < way[i].size(); j++) {
			path x = way[i][j];
			int to = x.second;
			int cos = x.first;
			if (ti_s[i] + cos + ti_t[to] == dist) { can_move_s[i].push_back(to); }
			if (ti_t[i] + cos + ti_s[to] == dist) { can_move_t[i].push_back(to); }
		}
	}
	vel com_s(n, 0); com_s[s] = 1;
	vel com_t(n, 0); com_t[t] = 1;
	vector<path> li_s(n);
	vector<path> li_t(n);
	for (int i = 0; i < n; i++) {
		li_s[i] = mkp(ti_s[i], i);
		li_t[i] = mkp(ti_t[i], i);
	}
	sort(li_s.begin(), li_s.end());
	sort(li_t.begin(), li_t.end());
	for (int i = 0; i < n; i++) {
		path x = li_s[i];
		int num = x.second;
		for (int j = 0; j < can_move_s[num].size(); j++) {
			int to = can_move_s[num][j];
			com_s[to] += com_s[num];
			ref(com_s[to]);
		}
	}
	for (int i = 0; i < n; i++) {
		path x = li_t[i];
		int num = x.second;
		for (int j = 0; j < can_move_t[num].size(); j++) {
			int to = can_move_t[num][j];
			com_t[to] += com_t[num];
			ref(com_t[to]);
		}
	}
	int ans = com_s[t] * com_t[s];
	ref(ans);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < can_move_s[i].size(); j++) {
			int to = can_move_s[i][j];
			if (ti_s[i] * 2 < dist and ti_t[to] * 2 < dist) {
				int x= (com_s[i] * com_t[to])%p;
				ans -= x * x;
				ref(ans);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (ti_s[i] * 2 == dist and ti_t[i] * 2 == dist) {
			int x=(com_s[i] * com_t[i])%p;
			ans -= x * x;
			ref(ans);
		}
	}
	cout << ans << endl;
	return 0;
}