#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<map>
#include<stack>
#include<queue>

#define ipair pair<int,int>
#define rep(i,n) for(i=0;i<n;i++)

using namespace std;

typedef long long int lli;
typedef vector<int> vi;
stack< pair<int, vector<bool> > > s;
vector< ipair > a;

int main() {
	int n, m, i, j, k;
	pair<int, vector<bool> > x, y;
	vector<bool>c;

	cin >> n >> m;

	c.resize(n);
	a.resize(2 * m);

	rep(i, n) {
		c[i] = false;
	}
	c[0] = true;

	rep(i, m) {
		cin >> j >> k;
		a[i].first = j;
		a[i].second = k;
		a[i + m].first = k;
		a[i + m].second = j;
	}
	sort(a.begin(), a.end());

	x.first = 1;
	x.second = c;

	s.push(x);
	k = 0;
	while (s.empty()!=1) {
		y = x = s.top();
		s.pop();

		rep(i, n) {
			if (!x.second[i])
				break;
		}
		if (i == n)
			k++;
		else {
			rep(i, 2 * m) {
				if (a[i].first == x.first && !x.second[a[i].second - 1]) {
					y = x;
					y.first = a[i].second;
					y.second[a[i].second - 1] = true;
					s.push(y);
				}
			}
		}
	}

	cout << k;

	return 0;
}