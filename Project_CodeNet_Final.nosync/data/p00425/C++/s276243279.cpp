#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

int main()
{
	while(1)
	{
		int n;
		int up=1,front=2,right=3;
		scanf("%d",&n);
		int ans=1;
		if(n==0) break;
		for(int i=0;i<n;i++)
		{
			string query;
			cin>>query;
			int up_=up,front_=front,right_=right;
			if(query=="North")
			{
				up=front_,front=7-up_,right=right_;
			}
			else if(query=="East")
			{
				up=7-right_,front=front_,right=up_;
			}
			else if(query=="West")
			{
				up=right_,front=front_,right=7-up_;
			}
			else if(query=="South")
			{
				up=7-front_,front=up_,right=right_;
			}
			else if(query=="Right")
			{
				up=up_,front=right_,right=7-front_;
			}
			else if(query=="Left")
			{
				up=up_,front=7-right_,right=front_;
			}
			ans+=up;
		}
		printf("%d\n",ans);
	}
	return 0;
}