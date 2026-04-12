#include<bits/stdc++.h>
using namespace std;

int n,m;
char a[110][110];

int main()
{int i,j,x,y,f1,f2,s;
 
 scanf("%d%d",&n,&m);
 s=0;
 for(i=1;i<=n;i++)
 {	scanf("%s",a[i]+1);
 	for(j=1;j<=m;j++)
 		s+=a[i][j]=='#';
 }
 x=1;
 y=1;
 if(a[1][1]!='#')
 {	printf("Impossible\n");
 	return 0;
 }
 else
 	s--;
 while(x!=n || y!=m)
 {	f1=0;
 	if(y<m && a[x][y+1]=='#') f1=1;
 	f2=0;
 	if(x<n && a[x+1][y]=='#') f2=1;
 	if(f1^f2)
 	{	s--;
	 	if(f1)
 			y++;
 		else
 			x++;
 	}
 	else
 		break;
 }
 if(!s)
 	printf("Possible\n");
 else
 	printf("Impossible\n");
 return 0;
}