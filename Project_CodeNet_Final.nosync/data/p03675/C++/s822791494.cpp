#include <bits/stdc++.h>
using namespace std;

deque<int> v;
int n, x;

int main()
{
	scanf("%d", &n);
	for (int i = 0;i < n;i++)
	{
		scanf("%d", &x);
		if (i&1) v.push_front(x);
		else v.push_back(x);
	}
	vector<int> ans(v.begin(), v.end());
	if (n&1) reverse(ans.begin(), ans.end());
	for (int u: ans) printf("%d ", u); printf("\n");
	return 0;
}
