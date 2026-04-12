#include <iostream>
using namespace std;
long long a[55];
bool Find;
int main()
{
	long long n,i,j,cnt,ans=0;
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	Find=true;
	while(Find)
	{
		Find=false;
		for(i=1;i<=n;i++)
		{
			if(a[i]>=n)
			{
				Find=true;
				cnt=a[i]/n;
				a[i]=a[i]%n;
				ans+=cnt;
				for(j=1;j<=n;j++)
				{
					if(j!=i)a[j]=a[j]+cnt;
				}
			}
		}
	}
	cout<<ans;
}