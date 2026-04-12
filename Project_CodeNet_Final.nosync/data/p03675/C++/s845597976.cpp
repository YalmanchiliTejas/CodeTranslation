#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+20;
const ll mod=1e9+7;
int n,a[N],b[N];
int main()
{
	while(cin>>n)
	{
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		int cnt=0,l=1,r=n;
		for(int i=n;i>=1;i--)
		{
			if(cnt%2)
				b[r--]=a[i];
			else
				b[l++]=a[i];
			cnt=1-cnt;
		}
		for(int i=1;i<=n;i++)
			cout<<b[i]<<' ';
		cout<<endl;
	}
	return 0;
}