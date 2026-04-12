#include <iostream>
using namespace std;
int main()
{
	long long n,maxv=-1,total=0;
	cin>>n;
	long long a[n];
	for (int i=1;i<=n;i++)  cin>>a[i];
	for (int i=1;i<=n;i++)
	{
		if (a[i]>=maxv)
		{
			maxv=a[i];
			total++;
		}
	}
	cout<<total<<endl;
	return 0;
}