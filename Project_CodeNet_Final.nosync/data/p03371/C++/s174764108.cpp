#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	long long ans=0,ans1=0x3f3f3f3f; 
	int A,B,C;
	int x,y;
	cin>>A>>B>>C>>x>>y;
	if(A+B>=C*2)
	{
		int n=min(x,y)*2;
		ans=ans+n*C;
		if(x>y)
		{
			ans=ans+(x-y)*A;
				
		}
		else
		{
			ans=ans+(y-x)*B;
		}
		ans1=max(x,y)*2*C;
	}
	else
	{
		ans=ans+A*x+B*y;
	}
	cout<<min(ans,ans1);
	return 0;
}
