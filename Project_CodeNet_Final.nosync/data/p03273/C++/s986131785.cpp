#include <bits/stdc++.h>
using namespace std;

int n,m;
int ans[105][105];
char ch;

int main()
{
	scanf("%d%d\n",&n,&m);
	for(int i=1;i<=n;i++)
	{
	  for(int j=1;j<=m;j++)
	  {
	    scanf("%c",&ch);
	    if(ch=='.') ans[i][j]=0;
	    else ans[i][j]=1;
	  }
	  scanf("\n");
	}
	for(int i=1;i<=n;i++)
	{
	  int sum=0;
	  for(int j=1;j<=m;j++) if(!ans[i][j]) sum++;
	  if(sum==m)
	  {
	    for(int j=i+1;j<=n;j++) for(int k=1;k<=m;k++) ans[j-1][k]=ans[j][k];
	    n--,i--;
	  }
	}
	for(int i=1;i<=m;i++)
	{
	  int sum=0;
	  for(int j=1;j<=n;j++) if(!ans[j][i]) sum++;
	  if(sum==n)
	  {
	    for(int j=i+1;j<=m;j++) for(int k=1;k<=n;k++) ans[k][j-1]=ans[k][j];
	    m--,i--;
	  }
	}
	if(!m || !n) cout<<"\n";
	for(int i=1;i<=n;i++)
	{
	  for(int j=1;j<=m;j++) if(ans[i][j]) cout<<"#";else cout<<"."; 
	  cout<<"\n";
	}
	return 0;
}