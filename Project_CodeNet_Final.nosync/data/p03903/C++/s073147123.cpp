# include "bits/stdc++.h"
using namespace std;
using LL = long long;
using ULL = unsigned long long;
const double PI = acos(-1);
template<class T>constexpr T INF() { return ::std::numeric_limits<T>::max(); }
template<class T>constexpr T HINF() { return INF<T>() / 2; }
template <typename T_char>T_char TL(T_char cX) { return tolower(cX); };
template <typename T_char>T_char TU(T_char cX) { return toupper(cX); };
const int vy[] = { -1, -1, -1, 0, 1, 1, 1, 0 }, vx[] = { -1, 0, 1, 1, 1, 0, -1, -1 };
const int dx[4] = { -1,0,1,0 }, dy[4] = { 0,-1,0,1 };
int popcnt(unsigned long long n) { int cnt = 0; for (int i = 0; i < 64; i++)if ((n >> i) & 1)cnt++; return cnt; }
int d_sum(LL n) { int ret = 0; while (n > 0) { ret += n % 10; n /= 10; }return ret; }
int d_cnt(LL n) { int ret = 0; while (n > 0) { ret++; n /= 10; }return ret; }
LL gcd(LL a, LL b) { if (b == 0)return a; return gcd(b, a%b); };
LL lcm(LL a, LL b) { LL g = gcd(a, b); return a / g*b; };
# define ALL(qpqpq)           (qpqpq).begin(),(qpqpq).end()
# define UNIQUE(wpwpw)        (wpwpw).erase(unique(ALL((wpwpw))),(wpwpw).end())
# define LOWER(epepe)         transform(ALL((epepe)),(epepe).begin(),TL<char>)
# define UPPER(rprpr)         transform(ALL((rprpr)),(rprpr).begin(),TU<char>)
# define FOR(i,tptpt,ypypy)   for(LL i=(tptpt);i<(ypypy);i++)
# define REP(i,upupu)         FOR(i,0,upupu)
# define INIT                 std::ios::sync_with_stdio(false);std::cin.tie(0)
# pragma warning(disable:4996)

int n;
int m;
struct edge { int from, to, cost; };
struct edge2 { LL to, cost; };
typedef pair<int, int> PP;

vector<edge> e;
vector<edge2> G[4040];

int Par[100000];
int Rank[100000];

void init(int n) {
	for (int i = 0; i < n; i++) {
		Par[i] = i;
		Rank[i] = 0;
	}
}

int find(int x) {
	if (Par[x] == x) {
		return x;
	}
	else {
		return Par[x] = find(Par[x]);
	}
}

void unite(int  x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	if (Rank[x] < Rank[y]) {
		Par[x] = y;
	}
	else {
		Par[y] = x;
		if (Rank[x] == Rank[y])Rank[x]++;
	}
}

bool same(int x, int y) {
	return find(x) == find(y);
}

// ソート時に比較するための関数 
bool comp(const edge& e1, const edge& e2) {
	return e1.cost < e2.cost;
}

LL kruskal() {
	init(n);
	sort(e.begin(), e.end(), comp);
	LL ans = 0;
	for (int i = 0; i < m; i++) {
		if (!same(e[i].from, e[i].to)) {
			unite(e[i].from, e[i].to);
			G[e[i].from].emplace_back(edge2{ e[i].to,e[i].cost });
			G[e[i].to].emplace_back(edge2{ e[i].from,e[i].cost });
			ans += e[i].cost;
		}
	}
	return ans;
}

LL ans[4040][4040];

int main() {
	cin >> n >> m;
	REP(i, m) {
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		e.emplace_back(edge{ a,b,c });
	}
	LL num = kruskal();
	REP(i, n) {
		stack<pair<int, int>> q;
		q.push(make_pair(i, -1));
		while (!q.empty()) {
			pair<int, int> cur = q.top();
			q.pop();
			REP(j, G[cur.first].size()) {
				if (G[cur.first][j].to != cur.second) {
					ans[i][G[cur.first][j].to] = max(ans[i][cur.first], G[cur.first][j].cost);
					q.push(make_pair(G[cur.first][j].to, cur.first));
				}
			}
		}
	}
	int q;
	cin >> q;
	REP(qqq, q) {
		int s, t;
		cin >> s >> t;
		s--, t--;
		cout << num - ans[s][t] << endl;
	}
}