#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
#define rep2(x,from,to) for(int x=(from);x<(to);++(x))
#define rep(x,to) rep2(x,0,to)
#define pint pair<string, int>
bool desc(pint a, pint b) {
	return a.second > b.second;
}
int main() {
	int n;
	bool f = 0;
	while(cin >> n, n) {
		if(f) cout << endl;
		f = 1;
		vector<pint> v;
		rep(i,n) {
			string t;
			int tmp, s = 0;
			cin >> t;
			cin >> tmp;
			s += tmp * 3;
			cin >> tmp;
			cin >> tmp;
			s += tmp;
			v.push_back(make_pair(t,s));
		}
		sort(v.begin(), v.end(), desc);
		for(pint p : v) {
			cout << p.first << "," << p.second << endl;
		}
	}
	return 0;
}