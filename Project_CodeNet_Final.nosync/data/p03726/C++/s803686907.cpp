#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <cmath>
#include <functional>
using namespace std;

vector<vector<int>>E;
int solve(int pre, int pos) {
	int cnt = 0;
	bool flag = false;
	for (int i = 0; i < E[pos].size(); i++) {
		if (E[pos][i] == pre)continue;

		int s = solve(pos, E[pos][i]);
		if (s == 1)cnt++;
		else if (s == 2)flag = true;
	}

	if (flag)return 2;
	if (cnt == 1)return 0;
	else if (cnt == 0)return 1;
	else return 2;
}

int main()
{
	int N; cin >> N;
	E.resize(N);
	for (int i = 0; i < N - 1; i++) {
		int a, b; cin >> a >> b;
		--a; --b;
		E[a].push_back(b);
		E[b].push_back(a);
	}

	int s = solve(-1, 0);

	cout << (s ? "First" : "Second") << endl;

    return 0;
}

