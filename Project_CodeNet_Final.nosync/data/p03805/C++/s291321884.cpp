#include <bits/stdc++.h>
using namespace std;


int n, m;
int a[28], b[28];
bool reached[8];

int main(void)
{
	cin >> n >> m;

	int path[8][8] = {};
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		path[a-1][b-1] = 1;
		path[b-1][a-1] = 1;
	}

	vector<int> v(n-1);
	for (int i = 1; i < n; i++) {
		v[i-1] = i;
	}

	int count = 0;

	do {
		int cur_i = 0;
		int i;
		for (i = 0; i < v.size(); i++) {
			if (path[cur_i][v[i]] == 0)
				break;
			cur_i = v[i];
		}
		if (i == v.size())
			count++;
	} while (next_permutation(v.begin(), v.end()));

	cout << count << endl;

	return 0;
}
