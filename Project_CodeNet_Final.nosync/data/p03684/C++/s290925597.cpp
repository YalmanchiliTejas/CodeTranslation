// In the name of Allah 
#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7, MAX = 1e5+5;

int n, p[MAX], res;
pair<int, int> x[MAX], y[MAX];
vector<pair<int, pair<int, int> > > edge;

int fnd (int a) {
	return (p[a] == a ? a : p[a] = fnd(p[a]));
}

void uni (int a, int b) {
	p[fnd(b)] = fnd (a);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);	
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		x[i] = {a, i};
		y[i] = {b, i};
		p[i] = i;
	}
	sort (x, x+n); sort (y, y+n);
	for (int i = 0; i < n-1; i++) {
		edge.push_back( { x[i+1].first - x[i].first , {x[i].second, x[i+1].second}});
		edge.push_back( { y[i+1].first - y[i].first , {y[i].second, y[i+1].second}});
	}

	sort (edge.begin(), edge.end());
	for (int i = 0; i < 2*n-2; i++) {
		int a = edge[i].second.first, b = edge[i].second.second, w = edge[i].first;
		if ( fnd(a) != fnd(b) ) {
			res += w;
			uni (a, b);
			//cout << a << ' ' << b << endl;
		}
	}

	cout << res << endl;

	return 0;
}