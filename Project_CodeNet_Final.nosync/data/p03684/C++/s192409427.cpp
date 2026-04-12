#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <map>
#include <set>
#include <cstring>
#include <string>
#include <cctype>
#include <cassert>
#include <queue>

using namespace std;

#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i = 0; i < (n); i++)
#define repr(i,b,e) for(int i = (b); i <= (e); i++)
#define INF (1001001001)
#define EPS (1e-15)

#define pr(x) do{cout << (#x) << " = " << (x) << endl;}while(0)
#define pri(x,i) do{cout << (#x) << "[" << i << "] = " << (x[i]) << endl;}while(0)
#define pra(x,n) rep(__i,n) pri(x,__i);
#define prar(x,b,e) repr(__i,b,e) pri(x,__i);

typedef long long ll;
typedef pair<int, int> pint;
typedef vector<int> vint;

int in() {
	int a;
	scanf("%d ", &a);
	return a;
}

struct City;
vector<City> cities;

struct City {
	int index;
	int x, y;
	int par;
	int root() {
		if (par == index) return par;
		return par = cities[par].root();
	}
	void merge(int i) {
		if(index != i)
			cities[root()].par = cities[i].root();
	}
};

bool xcomp(const City &a, const City &b) {
	return a.x < b.x;
}

bool ycomp(const City &a, const City &b) {
	return a.y < b.y;
}

int main() {
	int N = in();
	cities.resize(N);
	rep(i, N) {
		cities[i].index = cities[i].par = i;
		cities[i].x = in();
		cities[i].y = in();
	}
	
	vector<City> cx = cities, cy = cities;
	sort(cx.begin(), cx.end(), xcomp);
	sort(cy.begin(), cy.end(), ycomp);
	
	typedef pair<int, pint> pip;
	priority_queue<pip> px, py;
	rep(i, N - 1) {
		px.push(mp(cx[i].x - cx[i + 1].x, mp(cx[i].index, cx[i + 1].index)));
		py.push(mp(cy[i].y - cy[i + 1].y, mp(cy[i].index, cy[i + 1].index)));
	}
	
	ll ans = 0;
	int t = 0;
	while (t < N - 1) {
		//pr(t);
		int xdiff = px.empty() ? INF : -px.top().first;
		int ydiff = py.empty() ? INF : -py.top().first;
		if (xdiff < ydiff) {
			pip top = px.top();
			px.pop();
			if (cities[top.second.first].root() != cities[top.second.second].root()) {
				cities[top.second.first].merge(top.second.second);
				ans += xdiff;
				t++;
			}
		}
		else {
			pip top = py.top();
			py.pop();
			if (cities[top.second.first].root() != cities[top.second.second].root()) {
				cities[top.second.first].merge(top.second.second);
				ans += ydiff;
				t++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
