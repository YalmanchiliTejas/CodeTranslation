#include<bits/stdc++.h>

#define HAS_TEST_CASE 0  // Do you forget to complete this?

namespace registerGen
{
typedef long long ll;

const int N=5e5;

int n,m,a[N+10];
char str[N+10];

inline void main()
{
	int x;
	scanf("%d",&x);
	if(x>=30)puts("Yes");
	else puts("No");
}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("tmp.out","w",stdout);
#endif
	int T=1;
#if HAS_TEST_CASE
	scanf("%d",&T);
#endif
	while(T--)registerGen::main();
	return 0;
}
