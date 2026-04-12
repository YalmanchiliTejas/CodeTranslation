#include<cstdio>
#include<deque>
#define f(i,a,b) for(register int i=(a),i##end=(b);i<=i##end;++i)
const int neko=200010;
int n,a[neko];
std::deque<int>q;
int main()
{
	scanf("%d",&n);
	f(i,1,n)scanf("%d",&a[i]);
	int opt=n&1;
	f(i,1,n)
	{
		if((i&1)^opt)q.push_back(a[i]);
		else q.push_front(a[i]);
	}while(!q.empty())printf("%d ",q.front()),q.pop_front();
	return 0;
}
