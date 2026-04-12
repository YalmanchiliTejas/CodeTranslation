#include<bits/stdc++.h>
#define lowbit(a) ((a)&(-(a)))
using namespace std;

void file(bool opt)
{
	if (opt&&fopen("in.txt", "r"))
	{
		freopen("in.txt", "r", stdin);
		//freopen("out.txt", "w", stdout);
	}
}

int n;
long long s[200000 + 5];
int check[200000 + 5];



int main()
{
	file(1);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)scanf("%lld", &s[i]);
	long long ans = 0;
	for (int c = 1; c < n; c++)
	{
		long long res = 0;
		for (int i = 0;; i++)
		{
			int l = i * c, r = n - 1 - i * c;
			if ((r%c == 0 && r <= l)||l>=n||r<0)break;
			res += s[l] + s[r];
			if (r > c)ans = max(ans, res);
		}
	}
	cout << ans << endl;
	return 0;
}
