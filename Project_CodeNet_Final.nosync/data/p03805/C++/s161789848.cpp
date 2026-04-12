#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<stdio.h>
#include<locale.h>
#include<math.h>
#include<set>
#include<stack>
#include<queue>
using namespace std;

int n,m;
bool pth[10][10];
int perm[10];
int ans=0;
int main()
{
 scanf("%d %d",&n,&m);
 for(int i=0;i<m;i++)
 {
	int a,b;
	scanf("%d %d",&a,&b);
	pth[a][b]=pth[b][a]=true;
 }
 for(int i=0;i<n;i++)
 {
	perm[i]=i+1;
 }

 do{
	bool flg=true;
	for(int i=0;i<(n-1);i++)
	{
	 if(!pth[perm[i]][perm[i+1]]){flg=false;break;}
	}
	if(flg){ans++;}
 }while(next_permutation(perm+1,perm+n));
 printf("%d",ans);
}