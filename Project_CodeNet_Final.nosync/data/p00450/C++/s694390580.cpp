#include<iostream>
#include<vector>
using namespace std;
main()
{
	int n;
	while(cin>>n,n)
	{
		int b[1<<17]={},w[1<<17]={};
		int pre,cb=0,cw=0;
		for(int i=1;i<=n;i++)
		{
			int c;cin>>c;
			if(i==1||c==pre)
			{
				if(c)b[cb]++;
				else w[cw]++;
			}
			else if(i%2==0)
			{
				if(c)
				{
					(b[cb]||!cb?b[cb]:b[--cb])+=w[cw]+1;
					w[cw]=0;
				}
				else
				{
					(w[cw]||!cw?w[cw]:w[--cw])+=b[cb]+1;
					b[cb]=0;
				}
			}
			else
			{
				if(c)b[(b[cb]?++cb:cb)]++;
				else w[(w[cw]?++cw:cw)]++;
			}
			pre=c;
		}
		int ans=0;
		for(int i=0;i<=cw;i++)
		{
			ans+=w[i];
		}
		cout<<ans<<endl;
	}
}