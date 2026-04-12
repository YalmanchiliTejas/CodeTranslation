#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int n, m, s;
bool v[10];
vector<int> a[10];
void f(int p, int q) {
	int i;
	if (v[p]) return;
	if (q == n) {
		s++;
		return;
	}
	v[p] = 1;
	for (i =0; i < a[p].size(); i++) {
		f(a[p][i], q + 1);
	}
	v[p] = 0;
}
int main()
{
	int i, t1, t2;
	cin >> n >> m;
	while (m--) {
		scanf ("%d %d", &t1, &t2);
		a[t1].push_back(t2);
		a[t2].push_back(t1);
	}
	f(1, 1);
	cout << s;
    return 0;
}
