#include <iostream>
using namespace std;
int main()
{
	int n;
	long int a[51];
	long int b[51];
	int c[51];
	long int d;
	long int countt = 0;
	int e;
	cin >> n;
	for(int i=0;i < n;i++)
	{
		cin >> a[i];
	}
	while(1)
	{
		d = 0;
		e = 1;
		for(int i=0;i < n;i++)
		{
			b[i] = a[i] / n;
			d+=b[i];
			if(b[i] != 0)
			{
				e = 0;
			}
		}
		if(e)
		{
			break;
		}
		for(int i=0;i < n;i++)
		{
			a[i]-=(b[i] * n);
			a[i]+=(d - b[i]);
		}
		countt+=d;
	}
	cout << countt << endl;
	return 0;
}