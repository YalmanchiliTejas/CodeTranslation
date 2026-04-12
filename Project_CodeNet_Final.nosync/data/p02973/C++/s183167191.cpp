#include <bits/stdc++.h>
using namespace std;

const int MAX = 3e5 + 5;
pair <int, int> v[MAX];

int main() {
	int n; scanf("%d", &n);

	vector <int> a(n + 1);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	reverse(a.begin() + 1, a.end());

	int m = 0;
	for(int i = 1; i <= n; i++) {
		int p = lower_bound(v + 1, v + m + 1, make_pair(a[i], (int) 1e9 + 5)) - v; //para permitir elementos iguales cambiar el 0 por INF, ej: 1e9
		v[p] = { a[i], i };

		if(p == m + 1)
			m++;

	}

	printf("%d\n", m);

	return 0;
}