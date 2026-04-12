#include <bits/stdc++.h>

using namespace std;

struct node{
	int pos, mid, val;
}a[200003];

int n, ans[200003];

bool cmp(node a, node b) {
	return a.val < b.val;
}

inline void read(int& x) {
	x = 0; char c = getchar();
	while(!isdigit(c)) c = getchar();
	while(isdigit(c)) x = x * 10 + c - '0', c = getchar();
}

int main() {
	read(n);
	for(int i = 1; i <= n; ++i) a[i].pos = i, read(a[i].val);
	sort(a + 1, a + n + 1, cmp);
	int where = n >> 1;
	for(int i = 1; i <= n; ++i) {
		if(i <= where) a[i].mid = a[where + 1].val;
		else a[i].mid = a[where].val;  
	}
	for(int i = 1; i <= n; ++i)
		ans[a[i].pos] = a[i].mid;
	for(int i = 1; i <= n; ++i) printf("%d ", ans[i]);
	return 0;
}