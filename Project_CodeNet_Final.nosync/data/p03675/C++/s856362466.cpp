#include<cstdio>
#include<queue>

#define gec     getchar
#define FILE(F) freopen(F".in","r",stdin),freopen(F".out","w",stdout)
#define DEBUG   fprintf(stderr,"Passing [%s] in Line (%d)\n",__FUNCTION__,__LINE__)

typedef long long ll;
template<typename T>
inline void read(T &x)
{
	x=0;bool f=0; char c=gec();
	for(;c<'0'||c>'9';c=gec())f=(c=='-');
	for(;c>='0'&&c<='9';c=gec())x=x*10+c-'0';
	x=f?-x:x;
}

const int MAXN(200010);
std::deque<int>que;
int n,a[MAXN],Now,_n;
int main()
{
	read(n);
	for(int i=1;i<=n;i++)read(a[i]);
	Now=0;
	for(int i=1;i<=n;i++)
	{	
		Now^=1;
		if(Now)que.push_back(a[i]);
		else  que.push_front(a[i]);
	}
	while(!que.empty())a[++_n]=que.front(),que.pop_front();
	if(!Now)for(int i=1;i<=n;i++)printf("%d ",a[i]);
	else for(int i=1;i<=n;i++)printf("%d ",a[n-i+1]);
	printf("\n");
	return 0;
}	