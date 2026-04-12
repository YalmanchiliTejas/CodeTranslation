#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int n, m, cnt;
vector<int> a[10];
bool v[10];

void f(int p, int c) {
	int i;
	if (c == n) {
		cnt++;
		return;
	}
	for (i = 0; i < a[p].size(); i++) {
		if (v[a[p][i]]) continue;
		v[a[p][i]] = 1;
		f(a[p][i], c + 1);
		v[a[p][i]] = 0;
	}
}

int main()
{
	int i, t1, t2;
	cin >> n >> m;
	for (i = 0; i < m; i++) {
		scanf("%d %d", &t1, &t2);
		a[t1].push_back(t2);
		a[t2].push_back(t1);
	}
	v[1] = 1;
	f(1, 1);
    cout << cnt << endl;
    return 0;
}