#include <cstdio>
#include <cstring>
char s[100001];int n,k;int f[111][11][2];
int dfs(int cur,int cnt,bool lim)
{
	if(cnt>k)return f[cur][cnt][lim]=0;
	if(~f[cur][cnt][lim])return f[cur][cnt][lim];
	if(cur==n+1)return f[cur][cnt][lim]=(cnt==k);int ans=0;
	for(int i=0;i<=(lim?s[cur]-'0':9);++i)ans+=dfs(cur+1,cnt+!!i,lim&&i==s[cur]-'0');return f[cur][cnt][lim]=ans;
}
int main()
{
	scanf("%s%d",s+1,&k);n=strlen(s+1);memset(f,-1,sizeof(f));
	printf("%d\n",dfs(1,0,true));return 0;
}