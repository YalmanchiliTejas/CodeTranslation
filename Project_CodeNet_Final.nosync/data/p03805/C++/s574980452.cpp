#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;







int main(void)
{
	int N, M, a, b, ans = 0;
	queue<vector<int> > que;

	cin >> N >> M;

	vector<int> tmp, path;
	vector<vector<int>> edge(N, tmp);


	rep(i, M) {
		cin >> a >> b;
		a--; b--;

			edge[a].push_back(b);
			edge[b].push_back(a);		
	}

	rep(i, edge.size()) {
		sort(edge[i].begin(), edge[i].end());
	}

	tmp.clear();
	tmp.push_back(0);
	que.push(tmp);

	while (!que.empty()) {
		tmp = que.front();
		que.pop();

		if (tmp.size() >= N) {
			ans++;
			continue;
		}

		int node = tmp[tmp.size() - 1];
		rep(i, edge[node].size()) {
			if (find(tmp.begin(), tmp.end(), edge[node][i]) == tmp.end()) {
				path = tmp;
				path.push_back(edge[node][i]);
				que.push(path);
			}
		}

	}

	cout << ans << endl;




	return 0;
}
