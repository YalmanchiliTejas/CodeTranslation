#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define repbit(bit,n) for (int bit = 0; bit < (1<<n); bit++)
using namespace std;
typedef long long ll;

//const int INF = 1001001001;
//const ll INF = 1000000000000000000;

double dist(pair<int,int> a, pair<int,int> b){
	double dx, dy;
	dx = a.first - b.first;
	dy = a.second - b.second;
	return sqrt(dx*dx + dy*dy);
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> to(n);
	rep(i,m) {
		int a, b;
		cin >> a >> b; a--; b--;
		to[a].push_back(b);
		to[b].push_back(a);
	}

	vector<int> one_case(n);
	rep(i,n) one_case[i] = i;
	int ans = 0;
	do {
		if (one_case[0] != 0) continue;
		bool visited = false;
		rep(i,n) {
			if (i == 0) continue;
			int pre_pos = one_case[i - 1], pos = one_case[i];
			for (auto x : to[pre_pos]) {
				if (x == pos) {
					visited = true;
					break;
				}
				else visited = false;
			}
			if (!visited) break;
		}
		if (!visited) continue;
		ans++;
	} while(next_permutation(one_case.begin(), one_case.end()));
	cout << ans << endl;
	return 0;
} 
