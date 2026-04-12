//stl
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>

//std
#include <cmath>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ls(o) ((o)<<1  )
#define rs(o) ((o)<<1|1)

//macro
typedef long long LL;
using namespace  std;
//-----------------------------------------------------
char str[20][20];
//-----------------------------------------------------
int  main()
{

	//( "xx.in"  , "r" , stdin  );
	//freopen( "xx.out" , "w" , stdout );

	//--0 init
	
	//--1 read
	int n,m; scanf("%d%d",&n,&m);
	for (int i=1; i<=n; i++) scanf(" %s",str[i]+1);
	
	bool can=(str[1][1]=='#');
	str[1][1]='.';
	int x=1,y=1;
	for (; x<n||y<m; ) {
		int road=0;
		//printf("%d %d\n",x,y);
		//fflush(stdout);
		
		if (str[x+1][y]=='#') road+=1;
		if (str[x][y+1]=='#') road+=2;
		if (road>3||road==0) { 
			can=false;
			break;
		}
		if (road==1) x++;
			else y++;
		str[x][y]='.';
	}
	for (int i=1; i<=n; i++)
	for (int j=1; j<=m; j++) if (str[i][j]=='#') can=false;
	printf(can?"Possible":"Impossible");
}







