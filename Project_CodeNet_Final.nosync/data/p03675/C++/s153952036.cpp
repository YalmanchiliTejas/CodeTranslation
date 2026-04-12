#include<bits/stdc++.h>
using namespace std;
deque<int> Q;
int main()
{
	bool h=0;
	int n,x;cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if(!h) Q.push_back(x);
		else   Q.push_front(x);
		h^=1;
	}
	if(!h)
		while(!Q.empty())
		{
			printf("%d ",Q.front());
			Q.pop_front();
		}
	else
		while(!Q.empty())
		{
			printf("%d ",Q.back());
			Q.pop_back();
		}
	return 0;
}