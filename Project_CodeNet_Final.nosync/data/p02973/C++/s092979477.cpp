#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+100;
int n;
int a[N];
int ans[N];
int main()
{
	cin >> n ;
	int cnt = 0;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		a[i]=-a[i];
		if(cnt==0)
		{
			ans[cnt++] = a[i];
			continue;
		}
		int k = upper_bound(ans,ans+cnt,a[i])-ans;
		if(k==cnt)
		{
			ans[cnt++] = a[i];
		}
		else 
		{
				ans[k] = a[i];
		}
	}
	cout << cnt <<endl; 
	return 0;
}