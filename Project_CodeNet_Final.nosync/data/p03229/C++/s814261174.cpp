#include<bits/stdc++.h>
typedef long long ll;
const int maxn = 100003;

int n,a[maxn],b[maxn];
ll ans;

int read()
{
	char ch = getchar();
	int num = 0;
	bool fl = 0;
	for (; !isdigit(ch); ch=getchar())
		if (ch=='-') fl = 1;
	for (; isdigit(ch); ch=getchar())
		num = (num<<1)+(num<<3)+ch-48;
	if (fl) num = -num;
	return num;
}
int main()
{
	n = read();
	for (int i=1; i<=n; i++) a[i] = read();
	std::sort(a+1, a+n+1);
	b[1] = a[(n+1)/2];
	int l = 1, r = n, cnt = 1;
	for (int i=1, f=0; i<n; i++)
	{
		if (f) b[++cnt] = a[r--];
		else b[++cnt] = a[l++];
		f = 1-f;
	}
	ans = 0;
	for (int i=2; i<=n; i++)
		ans += abs(1ll*b[i]-b[i-1]);
	l = 1, r = n, cnt = 1;
	for (int i=1, f=1; i<n; i++)
	{
		if (f) b[++cnt] = a[r--];
		else b[++cnt] = a[l++];
		f = 1-f;
	}
	ll s = 0;
	for (int i=2; i<=n; i++)
		s += abs(1ll*b[i]-b[i-1]);
	printf("%lld\n",std::max(ans, s));
	return 0;
}