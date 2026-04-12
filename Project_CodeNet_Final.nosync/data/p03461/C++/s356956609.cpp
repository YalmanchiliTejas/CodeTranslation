#include <bits/stdc++.h>

using namespace std;

int a, b, d[11][11], ta, tb, tc;
pair< pair< int, int >, int > p[11][11];
vector< pair< pair< int, int >, int > > v;
bool u[101][101];

int main() {
	scanf("%d%d", &a, &b);
	for (int i = 1; i <= a; i++)
		for (int j = 1; j <= b; j++)
			scanf("%d", d[i] + j), p[i][j].second = -1;
	for (int i = 0; i <= 100; i++)
		for (int j = 0; j <= 100; j++) {
			ta = INT_MIN;
			for (int ii = 1; ii <= a; ii++)
				for (int jj = 1; jj <= b; jj++)
					ta = max(ta, d[ii][jj] - ii * i - jj * j);
			if (ta >= 0 && ta <= 100)
				for (int ii = 1; ii <= a; ii++)
					for (int jj = 1; jj <= b; jj++)
						if (ta == d[ii][jj] - ii * i - jj * j)
							p[ii][jj] = make_pair(make_pair(i, j), ta);
		}
	for (int i = 1; i <= a; i++)
		for (int j = 1; j <= b; j++)
			if (p[i][j].second == -1) {
				printf("Impossible\n");
				return 0;
			}
	for (int i = 1; i <= 100; i++)
		v.push_back(make_pair(make_pair(i, i + 1), -1));
	for (int i = 1; i <= 100; i++)
		v.push_back(make_pair(make_pair(101 + i, 101 + i + 1), -2));
	for (int i = 1; i <= a; i++)
		for (int j = 1; j <= b; j++) {
			ta = p[i][j].first.first;
			tb = p[i][j].first.second;
			tc = p[i][j].second;
			if (!u[ta][tb]) {
				u[ta][tb] = 1;
				v.push_back(make_pair(make_pair(ta + 1, 101 + 100 + 1 - tb), tc));
			}
		}
	printf("Possible\n%d %d\n", 101 + 100 + 1, v.size());
	for (int i = 0; i < v.size(); i++) {
		printf("%d %d ", v[i].first.first, v[i].first.second);
		if (v[i].second == -1)
			printf("X\n");
		else if (v[i].second == -2)
			printf("Y\n");
		else
			printf("%d\n", v[i].second);
	}
	printf("%d %d\n", 1, 101 + 100 + 1);
	return 0;
}