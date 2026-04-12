#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	auto e = vector<vector<int>>(n + 1);
	for(auto i = 0; i < m; ++i){
		int a, b;
		cin >> a >> b;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	auto solve = [&e](auto solve, int p, vector<bool> chk, int rem) -> int {
		if(rem == 0){
			return 1;
		}
		int ret = 0;
		for(auto next : e[p]){
			if(chk[next]) continue;
			chk[next] = true;
			ret += solve(solve, next, chk, rem - 1);
			chk[next] = false;
		}
		return ret;
	};
	auto c = vector<bool>(n + 1);
	c[1] = true;
	
	cout << solve(solve, 1, c, n - 1) << endl;
	return 0;
}