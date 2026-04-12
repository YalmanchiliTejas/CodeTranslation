#include<bits/stdc++.h>

using namespace std;

int main()
{
	long long n,k;
	scanf("%lld %lld",&n,&k);
	long long ans = 0;
	for(long long b = k+1; b <= n; b++)
	{
		long long q = n/b;
//		cout << b << ' ' << b-k << endl;
		ans += (b-k)*q;
		if(k == 0)
			ans--;
		ans += max(0LL,n-(b*q+k)+1);
	}
	printf("%lld\n",ans);
	return 0;
}
