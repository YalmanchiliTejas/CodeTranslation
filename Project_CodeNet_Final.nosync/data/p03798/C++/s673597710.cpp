#include <stdio.h>

char re[100001],ans[100001],tmp;

int main()
{
	int n,i;
	bool flag=1;
	scanf("%d%s",&n,&re);
	ans[0]='S';
	if(re[0]=='o') ans[1]='S',ans[n-1]=tmp='S';
	else ans[1]='S',ans[n-1]=tmp='W';
	//printf("first : %s\n",ans);
	for(i=1;i<n-1;i++)
	{
		if(re[i]=='o' && ans[i]=='S') ans[i+1]=ans[i-1];
		else if(re[i]=='o' && ans[i]=='W') ans[i+1]='S'+'W'-ans[i-1];
		else if(re[i]=='x' && ans[i]=='S') ans[i+1]='S'+'W'-ans[i-1];
		else ans[i+1]=ans[i-1];
		//printf("%d : %s\n",i,ans);
	}
	if(ans[n-1]!=tmp) flag=0;
	else if(re[n-1]=='o' && ans[n-1]=='S' && ans[0]!=ans[n-2]) flag=0;
	else if(re[n-1]=='x' && ans[n-1]=='W' && ans[0]!=ans[n-2]) flag=0;
	else if(re[n-1]=='o' && ans[n-1]=='W' && ans[0]==ans[n-2]) flag=0;
	else if(re[n-1]=='x' && ans[n-1]=='S' && ans[0]==ans[n-2]) flag=0;
	else printf("%s\n",ans);
	//
	if(flag) return 0;
	flag=1;
	ans[0]='S';
	if(re[0]=='o') ans[1]='S',ans[n-1]=tmp='S';
	else ans[1]='W',ans[n-1]=tmp='S';
	for(i=1;i<n-1;i++)
	{
		if(re[i]=='o' && ans[i]=='S') ans[i+1]=ans[i-1];
		else if(re[i]=='o' && ans[i]=='W') ans[i+1]='S'+'W'-ans[i-1];
		else if(re[i]=='x' && ans[i]=='S') ans[i+1]='S'+'W'-ans[i-1];
		else ans[i+1]=ans[i-1];
	}
	if(ans[n-1]!=tmp) flag=0;
	else if(re[n-1]=='o' && ans[n-1]=='S' && ans[0]!=ans[n-2]) flag=0;
	else if(re[n-1]=='x' && ans[n-1]=='W' && ans[0]!=ans[n-2]) flag=0;
	else if(re[n-1]=='o' && ans[n-1]=='W' && ans[0]==ans[n-2]) flag=0;
	else if(re[n-1]=='x' && ans[n-1]=='S' && ans[0]==ans[n-2]) flag=0;
	else printf("%s\n",ans);
	//
	if(flag) return 0;
	flag=1;
	ans[0]='S';
	if(re[0]=='o') ans[1]='W',ans[n-1]=tmp='W';
	else ans[1]='W',ans[n-1]=tmp='S';
	for(i=1;i<n-1;i++)
	{
		if(re[i]=='o' && ans[i]=='S') ans[i+1]=ans[i-1];
		else if(re[i]=='o' && ans[i]=='W') ans[i+1]='S'+'W'-ans[i-1];
		else if(re[i]=='x' && ans[i]=='S') ans[i+1]='S'+'W'-ans[i-1];
		else ans[i+1]=ans[i-1];
	}
	if(ans[n-1]!=tmp) flag=0;
	else if(re[n-1]=='o' && ans[n-1]=='S' && ans[0]!=ans[n-2]) flag=0;
	else if(re[n-1]=='x' && ans[n-1]=='W' && ans[0]!=ans[n-2]) flag=0;
	else if(re[n-1]=='o' && ans[n-1]=='W' && ans[0]==ans[n-2]) flag=0;
	else if(re[n-1]=='x' && ans[n-1]=='S' && ans[0]==ans[n-2]) flag=0;
	else printf("%s\n",ans);
	//
	if(flag) return 0;
	flag=1;
	ans[0]='W';
	if(re[0]=='o') ans[1]='S',ans[n-1]=tmp='W';
	else ans[1]='W',ans[n-1]=tmp='W';
	for(i=1;i<n-1;i++)
	{
		if(re[i]=='o' && ans[i]=='S') ans[i+1]=ans[i-1];
		else if(re[i]=='o' && ans[i]=='W') ans[i+1]='S'+'W'-ans[i-1];
		else if(re[i]=='x' && ans[i]=='S') ans[i+1]='S'+'W'-ans[i-1];
		else ans[i+1]=ans[i-1];
	}
	if(ans[n-1]!=tmp) flag=0;
	else if(re[n-1]=='o' && ans[n-1]=='S' && ans[0]!=ans[n-2]) flag=0;
	else if(re[n-1]=='x' && ans[n-1]=='W' && ans[0]!=ans[n-2]) flag=0;
	else if(re[n-1]=='o' && ans[n-1]=='W' && ans[0]==ans[n-2]) flag=0;
	else if(re[n-1]=='x' && ans[n-1]=='S' && ans[0]==ans[n-2]) flag=0;
	else printf("%s\n",ans);
	//
	if(flag) return 0;
	flag=1;
	ans[0]='W';
	if(re[0]=='o') ans[1]='W',ans[n-1]=tmp='S';
	else ans[1]='W',ans[n-1]=tmp='W';
	for(i=1;i<n-1;i++)
	{
		if(re[i]=='o' && ans[i]=='S') ans[i+1]=ans[i-1];
		else if(re[i]=='o' && ans[i]=='W') ans[i+1]='S'+'W'-ans[i-1];
		else if(re[i]=='x' && ans[i]=='S') ans[i+1]='S'+'W'-ans[i-1];
		else ans[i+1]=ans[i-1];
	}
	if(ans[n-1]!=tmp) flag=0;
	else if(re[n-1]=='o' && ans[n-1]=='S' && ans[0]!=ans[n-2]) flag=0;
	else if(re[n-1]=='x' && ans[n-1]=='W' && ans[0]!=ans[n-2]) flag=0;
	else if(re[n-1]=='o' && ans[n-1]=='W' && ans[0]==ans[n-2]) flag=0;
	else if(re[n-1]=='x' && ans[n-1]=='S' && ans[0]==ans[n-2]) flag=0;
	else printf("%s\n",ans);
	//
	if(flag) return 0;
	flag=1;
	ans[0]='W';
	if(re[0]=='o') ans[1]='W',ans[n-1]=tmp='S';
	else ans[1]='S',ans[n-1]=tmp='S';
	for(i=1;i<n-1;i++)
	{
		if(re[i]=='o' && ans[i]=='S') ans[i+1]=ans[i-1];
		else if(re[i]=='o' && ans[i]=='W') ans[i+1]='S'+'W'-ans[i-1];
		else if(re[i]=='x' && ans[i]=='S') ans[i+1]='S'+'W'-ans[i-1];
		else ans[i+1]=ans[i-1];
	}
	if(ans[n-1]!=tmp) flag=0;
	else if(re[n-1]=='o' && ans[n-1]=='S' && ans[0]!=ans[n-2]) flag=0;
	else if(re[n-1]=='x' && ans[n-1]=='W' && ans[0]!=ans[n-2]) flag=0;
	else if(re[n-1]=='o' && ans[n-1]=='W' && ans[0]==ans[n-2]) flag=0;
	else if(re[n-1]=='x' && ans[n-1]=='S' && ans[0]==ans[n-2]) flag=0;
	else printf("%s\n",ans);
	//
	if(flag) return 0;
	flag=1;
	ans[0]='W';
	if(re[0]=='o') ans[1]='S',ans[n-1]=tmp='W';
	else ans[1]='S',ans[n-1]=tmp='S';
	for(i=1;i<n-1;i++)
	{
		if(re[i]=='o' && ans[i]=='S') ans[i+1]=ans[i-1];
		else if(re[i]=='o' && ans[i]=='W') ans[i+1]='S'+'W'-ans[i-1];
		else if(re[i]=='x' && ans[i]=='S') ans[i+1]='S'+'W'-ans[i-1];
		else ans[i+1]=ans[i-1];
	}
	if(ans[n-1]!=tmp) flag=0;
	else if(re[n-1]=='o' && ans[n-1]=='S' && ans[0]!=ans[n-2]) flag=0;
	else if(re[n-1]=='x' && ans[n-1]=='W' && ans[0]!=ans[n-2]) flag=0;
	else if(re[n-1]=='o' && ans[n-1]=='W' && ans[0]==ans[n-2]) flag=0;
	else if(re[n-1]=='x' && ans[n-1]=='S' && ans[0]==ans[n-2]) flag=0;
	else printf("%s\n",ans);
	//
	if(flag) return 0;
	flag=1;
	ans[0]='S';
	if(re[0]=='o') ans[1]='W',ans[n-1]=tmp='W';
	else ans[1]='S',ans[n-1]=tmp='W';
	for(i=1;i<n-1;i++)
	{
		if(re[i]=='o' && ans[i]=='S') ans[i+1]=ans[i-1];
		else if(re[i]=='o' && ans[i]=='W') ans[i+1]='S'+'W'-ans[i-1];
		else if(re[i]=='x' && ans[i]=='S') ans[i+1]='S'+'W'-ans[i-1];
		else ans[i+1]=ans[i-1];
	}
	if(ans[n-1]!=tmp) flag=0;
	else if(re[n-1]=='o' && ans[n-1]=='S' && ans[0]!=ans[n-2]) flag=0;
	else if(re[n-1]=='x' && ans[n-1]=='W' && ans[0]!=ans[n-2]) flag=0;
	else if(re[n-1]=='o' && ans[n-1]=='W' && ans[0]==ans[n-2]) flag=0;
	else if(re[n-1]=='x' && ans[n-1]=='S' && ans[0]==ans[n-2]) flag=0;
	else printf("%s\n",ans);
	if(!flag) printf("-1\n");
}