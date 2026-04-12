#include<cstdio>
#include<map>
#include<queue>
#include<iostream>

using namespace std;

int n;
long long a[55];

int main()
{
	cin >> n;
	long long ans=0;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	bool flag=1;
	while(1)
	{
		flag=0;
		for(int i = 1;i <= n;i++)
			if(a[i]>=n)flag=1;
		if(!flag)break;
		for(int i = 1;i <= n;i++)
			if(a[i]>=n)
			{
				long long cnt=a[i];
				cnt/=n;
				a[i]-=cnt*n;
				ans+=cnt;
				for(int j = 1;j <= n;j++)
					if(i!=j)a[j]+=cnt;
			}
	}
	/*flag=1;
	while(1)
	{
		int ii=1;
		for(int i = 1;i <= n;i++)
			if(a[i]>a[ii])ii=i;
		ans++;
		a[ii]-=n;
		for(int i = 1;i <= n;i++)
			if(i!=ii)a[i]++;
		flag=0;
		for(int i = 1;i <= n;i++)
			if(a[i]>=n)flag=1;
	}*/
	cout << ans << endl;
	return 0;
}