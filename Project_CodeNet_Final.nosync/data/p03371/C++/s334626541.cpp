#include <iostream>

using namespace std;

int main()
{
	int a,b,c,x,y;
	long long t=0;
	cin>>a>>b>>c>>x>>y;

	if (a + b > 2 * c)
	{
		if (x < y)
		{
			t += 2 * x * c;
			if ((y-x) * b > (y-x)*2*c)
			{
				t += 2 * (y-x) * c;
			}
			else t += (y-x)*b;
		}	
		else
		{
			t += 2 * y * c;	
			if ((x-y) * a > (x-y)*2*c)
			{
				t += 2 * (x-y) * c;
			}
			else t += (x-y)*a;
		} 
	}
	else
	{
		t += a*x + b*y;
	}
	cout << t << "\n";
	return 0;
}