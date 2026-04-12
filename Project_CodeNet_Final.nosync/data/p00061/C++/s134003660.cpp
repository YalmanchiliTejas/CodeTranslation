#include <iostream>
#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
#define rep2(x,from,to) for(int x = (from); x < (to); ++(x))
#define rep(x,to) rep2(x,0,to)
int main() {
	int a, b;
	vector<pair<int, int> > v;
	while(scanf("%d,%d", &a, &b) && (a || b)) {
		v.push_back(make_pair(b, a));
	}
	sort(v.begin(), v.end(), greater<pair<int, int> >());
	int Rank[100];
	Rank[0] = 1;
	rep2(i,1,v.size()) {
		if(v[i].first != v[i-1].first) Rank[i] = Rank[i-1] + 1;
		else Rank[i] = Rank[i-1];
	}
	int c;
	while(cin >> c) {
		rep(i,v.size()) {
			if(v[i].second == c) cout << Rank[i] << endl;
		}
	}
	return 0;
}