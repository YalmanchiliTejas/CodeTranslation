#include<bits/stdc++.h>
using namespace std;

int n,p,t;
deque<int> q;

int main()
{
	scanf("%d",&n);
	p = 1;
	if(n&1)	p ^= 1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&t);
		if(p&1)	q.push_back(t);
		else q.push_front(t);
		p ^= 1;
	}
	while(!q.empty())
	{
		printf("%d ",q.front());
		q.pop_front();
	}
	return 0;
}
