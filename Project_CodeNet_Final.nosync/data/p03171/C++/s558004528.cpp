#include <iostream>

using namespace std;

const int N = 3010;
const long long inf = (1 << 50);

int n, i, j, v[N], x, y;
long long m[N][N], M[N][N];

inline long long minim(long long x, long long y) {
    return (x < y ? x : y);
}

inline long long maxim(long long x, long long y) {
    return (x > y ? x : y);
}

int main() {
	cin >> n;
	for (i = 1; i <= n; ++i) {
        cin >> v[i];
	}
	for (i = 1; i <= n; ++i) {
		M[i][i] = v[i];
        m[i][i] = -v[i];
		for (j = i + 1; j <= n; ++j) {
            M[i][j] = -inf;
            m[i][j] = inf;
		}
	}
	for (i = 2; i <= n; ++i)
		for (x = 1, y = i; y <= n; ++x, ++y) {
			M[x][y] = maxim(m[x + 1][y] + v[x], m[x][y - 1] + v[y]);
			m[x][y] = minim(M[x + 1][y] - v[x], M[x][y - 1] - v[y]);
		}
    cout << M[1][n] << "\n";
    return 0;
}
