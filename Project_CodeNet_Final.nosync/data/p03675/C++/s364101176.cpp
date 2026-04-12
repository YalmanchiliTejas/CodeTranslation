#include <stdio.h>
#include <deque>
#include <vector>
using namespace std;
int mt[200001],tmp[200001];
int main()
{
	int n;
	scanf("%d",&n);
	deque<int> dq;
	dq.push_back(1);
	int pos=1;
	for (int i=1;i<=(n-1)/2;++i)
		if (n%2)
		{
			dq.push_back(++pos);
			dq.push_front(++pos);
		}
		else
		{
			dq.push_front(++pos);
			dq.push_back(++pos);
		}
	if (n%2==0)
		dq.push_front(++pos);
	pos=0;
	for (deque<int>::iterator it=dq.begin();it!=dq.end();++it)
		mt[*it]=++pos;
	for (int i=1;i<=n;++i)
	{
		int c;
		scanf("%d",&c);
		tmp[mt[i]]=c;
	}
	for (int i=1;i<=n;++i)
		printf("%d ",tmp[i]);
	return 0;
}
