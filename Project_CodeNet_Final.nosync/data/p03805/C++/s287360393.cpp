#include<bitset>
#include<math.h>
#include<limits.h>
#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>
#include<sstream>
#include<list>
#include<queue>
#include<algorithm>
#include<functional>
#include<map>
#include<set>
#include<utility>
#include<initializer_list>
#include<tuple>
#include<regex>
using namespace std;
#define ull unsigned long long
#define ll long long
#define rep(i, n) for(int i=0;i<(int)(n);i++)
#define rep1n(i, n) for(int i=1;i<=(int)(n);i++)
#define all(t) t.begin(), t.end()
#define rall(t) t.rbegin(), t.rend()
#define mat(type, row, col, init) vector<vector<type>>(row, vector<type>(col, init));
#define Yes(cond) cout<<(cond? "Yes":"No")<<endl;
#define YES(cond) cout<<(cond? "YES":"NO")<<endl;
int dfs(vector<vector<int>>&g, vector<bool>used, int x) {
	//cout << x<<endl;
	int n = g.size();
	bool all = true;
	rep(i, n)if (used[i] == false) {
		all = false;
		break;
	}
	if (all) {
		//cout << endl;
		return 1;
	}

	int cnt = 0;
	rep(i, n) {
		if (g[x][i] == 1 && !used[i]) {
			used[i] = true;
			cnt += dfs(g, used, i);
			used[i] = false;
			
		}
	}
	//cout << "/" << x << endl;
	return cnt;


}
int main() {
	int n, m;
	cin >> n >> m;
	auto g = mat(int, n, n, -1);
	rep(i, m) {
		int a, b;
		cin >> a >> b;
		g[a - 1][b - 1] = g[b - 1][a - 1] = 1;
	}
	int cnt = 0;
	vector<bool>used(n, 0);
	used[0] = 1;
	cout << dfs(g, used, 0);



	return 0;
}



