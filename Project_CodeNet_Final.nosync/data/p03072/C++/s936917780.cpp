#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
int main()
{
	int n;
	scanf("%d", &n);
	vector<int> h(n);
	rep(i, n) scanf("%d", &h[i]);
	int hmax = 0, count = 1;
	rep(i, n - 1){
		hmax = max(hmax, max(h[i], h[i + 1]));
		if(hmax <= h[i + 1])count++;
	}
	printf("%d\n", count);
	return 0;
}