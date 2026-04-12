#include<cstdio>
#include<string>
#include<utility>
#include<algorithm>
using namespace std;
typedef pair<int,string>P;
bool F(P a,P b)
{return a.first>b.first;};
int main()
{
	int n,a,b,c,i,x=0;
	while(scanf("%d",&n),n)
	{
		char s[99];
		pair<int,string>p[10];
		for(i=0;i<n;++i)
			scanf("%s%d%d%d",s,&a,&b,&c),p[i].second=s,p[i].first=3*a+c;
		stable_sort(p,p+n,F);
		printf("%s",(x++?"\n":""));
		for(i=0;i<n;++i)
			printf("%s,%d\n",p[i].second.c_str(),p[i].first);
	}
	return 0;
}