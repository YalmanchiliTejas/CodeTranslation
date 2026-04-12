#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+10;

int a[maxn], cor[maxn];

int suf[maxn];

bool mark[maxn];

int main(void)
{
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	multiset<int> st;

	for (int i = 1; i <= n; i++)
	{
		auto pos = st.lower_bound(a[i]);

		if (pos == st.begin()) st.insert(a[i]);
		else
		{
			st.erase(--pos);
			st.insert(a[i]);
		}
	}	

	printf("%d\n", st.size());
}