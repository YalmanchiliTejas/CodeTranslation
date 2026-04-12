#include<iostream>
using namespace std;
main()
{
	int m;cin>>m;
	for(;m--;)
	{
		int L,y,n;cin>>L>>y>>n;
		int ans=0;
		for(;n--;)
		{
			int f,c;double d;
			cin>>f>>d>>c;
			int A=L,B=0;
			for(int i=0;i<y;i++)
			{
				if(f)A+=A*d;
				else B+=A*d;
				A-=c;
			}
			ans=ans<A+B?A+B:ans;
		}
		cout<<ans<<endl;
	}
}

