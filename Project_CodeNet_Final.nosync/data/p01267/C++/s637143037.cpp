#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<iomanip>
#include<set>

using namespace std;

int main()
{
	int n,a,b,c,x;
	while(true)
	{
		cin >> n >> a >> b >> c >> x;
		if(n==0)break;

		vector<int> y(n);
		for(int i=0;i<n;i++)cin >> y[i];
	
		int now=0;
		int ans=-1;
		for(int i=0;i<=10000;i++)
		{
			if(x==y[now])
				now++; 
			if(now>=n)
			{
				ans=i;
				break;
			}

			x=(a*x+b)%c;

		}

		cout << ans << endl;
	}

}
