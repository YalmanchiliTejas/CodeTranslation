#include<bits/stdc++.h>
using namespace std;

main(int argc, char const *argv[])
{
	int n,l,r;
	while(cin>>n>>l>>r,n)
	{
		int a[n],ans=0;
		for (int i = 0; i < n; ++i)
		{
			cin>>a[i];
		}

		for (int i = l; i <= r; ++i)
		{
			int f=1;
			for (int j = 0; j < n; ++j)
			{
				if(i%a[j]==0)
				{
					if(f%2) ++ans;
					f=0;
					break;
				}
				++f;
			}
			if(f%2) ++ans;
		}
		cout<<ans<<endl;
	}
	return 0;
}
