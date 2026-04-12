#include <bits/stdc++.h>
using namespace std;

int N;
vector< pair<int, int> > V;

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			printf("? ");
			for (int k = 0; k < N; k++) {
				if (i == k || j == k) printf("1");
				else printf("0");
			}
			printf("\n");
			fflush(stdout);
			int x;
			scanf("%d", &x);
			if (x == 1) V.push_back(make_pair(i, j));
		}
	}
	printf("! ");
	for (int i = 0; i < V.size(); i++) printf("(%d,%d) ", V[i].first, V[i].second);
	printf("\n");
}
