#include "iostream"
#include "algorithm"
#include "string"
#include "vector"
#include "cmath"
#include "bitset"
#include "queue"
#include "functional"
#include "map"
#include "unordered_map"
#include "set"
#include "stack"

#define lp(n) for (int i = 0; i < n; i++)
#define LP(n,i) for (int i = 0; i < n; i++)
#define mod 1000000007
#define sp ' '
#define intmax 2147483647
#define llmax 9223372036854775807
#define nya_n "(=^･ω･^=)"
typedef long long ll;
using namespace std;

int n;
pair<int, int>x[100000], y[100000];
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>q;
pair<int, int>g[100000];
ll cnt;
pair<int, pair<int, int>>m;
int mf, ms;

int uf(int x) {
	while (g[x].first != x)
		x = g[x].first;
	return x;
}


int main() {
	cin >> n;
	lp(n) {
		cin >> x[i].first >> y[i].first;
		x[i].second = y[i].second = i;
	}
	sort(x, x + n);
	sort(y, y + n);
	lp(n - 1) {
		q.push(make_pair(x[i + 1].first - x[i].first, make_pair(x[i].second, x[i + 1].second)));
		q.push(make_pair(y[i + 1].first - y[i].first, make_pair(y[i].second, y[i + 1].second)));
	}
	lp(n) {
		g[i] = make_pair(i, 1);
	}
	cnt = 0;
	lp(n - 1) {
		do {
			m = q.top();
			q.pop();
			mf = uf(m.second.first);
			ms = uf(m.second.second);
		} while (mf == ms);
		cnt += m.first;
		if (g[mf].second >= g[ms].second) {
			g[mf].second += g[ms].second;
			g[ms].first = mf;
		}
		else {
			g[ms].second += g[mf].second;
			g[mf].first = ms;
		}
	}
	cout << cnt << endl;
	return 0;
}
