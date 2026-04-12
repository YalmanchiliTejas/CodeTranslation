#include<bits/stdc++.h>
using namespace std;
deque<int> dq;
int n,a;
int main()
{
	scanf("%d",&n);
	if(n%2==1)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a);
			if(i%2==1)
			{
				dq.push_front(a);
			}else
			{
				dq.push_back(a);
			}
		}
	}else
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a);
			if(i%2==1)
			{
				dq.push_back(a);
			}else
			{
				dq.push_front(a);
			}
		}
	}
	while(!dq.empty())
	{
		printf("%d ",dq.front());
		dq.pop_front();
	}
}