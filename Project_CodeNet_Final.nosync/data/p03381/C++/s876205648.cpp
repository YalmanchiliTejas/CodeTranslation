#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n;
int a[200010];
vector<int> vt;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		vt.push_back(a[i]);
	}
	sort(vt.begin(), vt.end());
	int ch = vt[(n+1) / 2];
	for (int i = 0; i < n; i++)
	{
		if (a[i] < ch)
		{
			printf("%d\n", vt[(n+1) / 2]);
		}
		else
			printf("%d\n", vt[(n-1) / 2]);
	}
}