#include <cstdio>
#include <vector>
using namespace std;

int d[11][11];
int mx[110][110];

int main() {
	int A,B;
	scanf("%d %d", &A, &B);
	for (int i=1;i<=A;i++) {
		for (int j=1;j<=B;j++) {
			scanf("%d", &d[i][j]);
		}
	}

	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			// x간선 i개, y간선 j개
			
			for (int x = 1; x <= A; x++) {
				for (int y = 1; y <= B; y++) {
					mx[i][j] = max(mx[i][j], d[x][y] - x*i - y*j);
				}
			}
		}
	}
	

	for (int x = 1; x <= A; x++) {
		for (int y = 1; y <= B; y++) {

			int mi = 100 + 1;
			for (int i = 0; i <= 100; i++) {
				for (int j = 0; j <= 100; j++) {
					mi = min(mi, mx[i][j] + x*i + y*j);
				}
			}

			if (mi != d[x][y]) {
				puts("Impossible");
				return 0;
			}
		}
	}


	vector<int> a, b;
	for(int i=1;i<=101;i++)
		a.push_back(i);
	for(int i=102;i<=202;i++)
		b.push_back(i);

	int n, m;
	n = 202;
	m = 100*2 + 101*101;
	int S = a[0], T = b.back();

	puts("Possible");
	printf("%d %d\n", n, m);

	for (int i = 0; i < 100; i++) {
		printf("%d %d X\n", a[i], a[i+1]);
		printf("%d %d Y\n", b[i], b[i+1]);
	}

	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			printf("%d %d %d\n", a[i], b[j], mx[i][100-j]);
		}
	}

	printf("%d %d\n", S, T);
	return 0;
}