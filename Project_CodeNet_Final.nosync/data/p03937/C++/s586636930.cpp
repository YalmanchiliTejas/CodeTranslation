#include <bits/stdc++.h>
using namespace std;

char s[10][10];
vector<pair<int, int>> v;


int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0;i < n;i++) scanf("%s", s[i]);
	for(int i = 0;i < n;i++) 
		for(int j = 0;j < m;j++) if(s[i][j] == '#') v.push_back({i, j});
	sort(v.begin(), v.end());
	bool ret = true;
	//for(auto p: v) printf("%d, %d\n", p.first, p.second);
	if(v[0] != pair<int, int>(0, 0)) ret = false;
	for(int i = 1;i < v.size() and ret;i++) {
		auto pre = v[i - 1];
		if(v[i].first - pre.first >= 0 and v[i].second - pre.second >= 0) continue;
		ret = false;
	}
	puts(ret? "Possible": "Impossible");
	return 0;
}