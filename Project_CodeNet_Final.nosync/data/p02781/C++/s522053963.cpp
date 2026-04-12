#include<cstdio>
#include<cstring>
using namespace std;
char ch[110];
long long n[110],len;
long long k;
long long ans;
long long f[110][4][2];
long long dfs(long long now,long long last,bool check)
{
	if(last==k+1)
		return 0;
	if(now==len+1)
		return last==k;
	if(f[now][last][check]!=-1)
		return f[now][last][check];
	long long ret=0,p=check? n[now]:9;
	for(long long i=0;i<=p;i++)
		ret+=dfs(now+1,last+(i!=0),check&&(i==p));
	return f[now][last][check]=ret;
}
int main()
{
	scanf("%s",ch+1);
	scanf("%lld",&k);
	memset(f,-1,sizeof(f));
	len=strlen(ch+1);
	for(long long i=1;i<=len;i++)
		n[i]=ch[i]-'0';
	ans=dfs(1,0,1);
	printf("%lld\n",ans);
}