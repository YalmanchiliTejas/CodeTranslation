#include <bits/stdc++.h>
using namespace std;


#define _x real()
#define _y imag()
#define cross(a, b) (conj(a)*(b)).imag()
#define dot(a, b) (conj(a)*(b)).real()
#define PI acos(-1)
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL)
#define fileIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef complex<ld> point;
typedef tuple<int, int, int> line;
typedef vector<point> polygon;
typedef pair<double, double> pd;
pair<int, int> dirs[] = { {1, 0}, {0, 1}, {1, 1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {1, -1} };
ll mod = 1e9 + 7;

int sz[100007], rep[100007], nc;
vector<pair<int, int>> points;

bool compX(int a, int b) {
	if (points[a].first < points[b].first)
		return true;
	return false;
}

bool compY(int a, int b) {
	if (points[a].second < points[b].second)
		return true;
	return false;
}

int find(int u) {
	if (rep[u] == u)
		return u;
	return rep[u] = find(rep[u]);
}

void join(int a, int b) {
	a = find(rep[a]);
	b = find(rep[b]);
	if (a == b)
		return;
	if (sz[a] < sz[b])
		swap(a, b);
	rep[b] = a;
	sz[a] += sz[b];
	nc--;
}

int main() {
	fastIO;
	int n, mst = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		rep[i] = i;
		sz[i] = 1;
	}
	int idsX[n], idsY[n];
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		points.push_back({a, b});
		idsX[i] = i;
		idsY[i] = i;
	}
	sort(idsX, idsX+n, compX);
	sort(idsY, idsY+n, compY);

	map<int, vector<pair<int, int>>> diffs;
	for (int i = 1; i < n; i++) {
		int diffX = abs(points[idsX[i]].first - points[idsX[i-1]].first);
		int diffY = abs(points[idsY[i]].second - points[idsY[i-1]].second);
		diffs[diffX].push_back({idsX[i], idsX[i-1]});
		diffs[diffY].push_back({idsY[i], idsY[i-1]});
	}
	for (auto i : diffs) {
		for (auto j : i.second) {
			int a = j.first, b = j.second;
			if (find(rep[a]) != find(rep[b])) {
				join(a, b);
				mst += i.first;
			}
		}
	}
	cout << mst << endl;

}
