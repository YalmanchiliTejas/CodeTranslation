#include <bits/stdc++.h>
using namespace std;
#define FOR(i,k,n) for(int i = (k); i < (n); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(a) a.begin(), a.end()
#define MS(m,v) memset(m,v,sizeof(m))
#define D10 fixed<<setprecision(10)
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;
const int MOD = 1000000007;
const int INF = MOD + 1;
const ld EPS = 1e-12;
template<class T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template<class T> T &chmax(T &a, const T &b) { return a = max(a, b); }

/*--------------------template--------------------*/
struct UnionFind
{
	vector<int> par;
	UnionFind(int n) :par(n, -1) {}
	int find(int x) { return par[x] < 0 ? x : par[x] = find(par[x]); }
	void unite(int x, int y)
	{
		x = find(x); y = find(y);
		if (x == y) return;
		if (par[y] < par[x]) swap(x, y);
		if (par[x] == par[y]) par[x]--;
		par[y] = x;
		if (find(x) != find(y)) par[find(y)] = x;
	}
	int count()
	{
		int cnt = 0;
		REP(i, par.size()) if (par[i] < 0) cnt++;
		return cnt;
	}
	bool same(int x, int y)
	{
		return find(x) == find(y);
	}
};

struct Dice
{
private:
	int top, right, front;
public:
	Dice() :top(1), right(2), front(3) {};
	Dice(int t, int r, int f) :top(t), right(r), front(f) {};
	void set(int t, int r, int f) { top = t, right = r, front = f; }
	int get_top() { return top; }
	int get_bottom() { return 7-top; }
	int get_right() { return right; }
	int get_left() { return 7 - right; }
	int get_front() { return front; }
	int get_back() { return 7 - front; }
	void to_front() { swap(front, top); top = 7 - top; }
	void to_back() { REP(i, 3) to_front(); }
	void to_right() { swap(top, right); top = 7 - top; }
	void to_left() { REP(i, 3) to_right(); }
	void to_clock() { swap(front, right); right = 7 - right; }
	void to_counter() { REP(i, 3) to_clock(); }
};

int main()
{
	int n; 
	while (cin >> n, n)
	{
		Dice d(1, 3, 2);
		int ans = 1;
		REP(i, n)
		{
			string s; cin >> s;
			if (s == "North") d.to_back();
			else if (s == "South") d.to_front();
			else if (s == "East") d.to_right();
			else if (s == "West") d.to_left();
			else if (s == "Right") d.to_clock();
			else if (s == "Left") d.to_counter();
			ans += d.get_top();
		}
		cout << ans << endl;
	}
	return 0;
}