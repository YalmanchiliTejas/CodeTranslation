#include <bits/stdc++.h>
using namespace std;

const int maxN = 105;
const int MOD = 10000;

int a[maxN];
int n,m;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	int ans = a[1];
	int cnt = 1;
	for(int i=2;i<=n;i++)
	{
		ans = max(ans,a[i]);
		if(a[i]>=ans)
			cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}