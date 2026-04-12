#include <bits/stdc++.h>
using namespace std;

#define fo(i,s,t) for(int i = s; i <= t; ++ i)
const int maxn = 200050;

int n, a[maxn], l, r, b[maxn];

int main()
{
	scanf("%d",&n);
	fo(i,1,n) scanf("%d",&a[i]);
	b[n/2+1] = a[1]; l = r = n/2+1;
	for(int i = 2; i <= n; i += 2)
	{
		-- l; ++ r;
		if((n-i+1)%2==1) b[l] = a[i], b[r] = a[i+1];
		else b[r] = a[i], b[l] = a[i+1];
	}
	fo(i,1,n) printf("%d ",b[i]);
	return 0;
}