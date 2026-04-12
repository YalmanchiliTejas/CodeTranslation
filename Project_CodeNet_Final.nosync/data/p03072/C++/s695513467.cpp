#include <iostream>
using namespace std;
int cnt;
int main()
{
	int n, a[100];
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++)
	{
		int jud=1;
		for(int j=i-1;j>=0;j--)
		{
			if(a[j]>a[i])
			{
				jud=0;
				break;
			}
		}
		if(jud==1)cnt++;
	}
	cout<<cnt<<endl;
	
	return 0;
}