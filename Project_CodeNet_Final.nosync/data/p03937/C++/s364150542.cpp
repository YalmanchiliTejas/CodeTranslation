#include<cstdio>

const int N=8;
int h,w,cnt,fac;
char s[N+5][N+5];

int main()
{
	scanf("%d %d",&h,&w);
	for(int i=1;i<=h;i++)
		scanf("%s",s[i]+1);
	
	for(int i=1;i<=h;i++)
		for(int j=1;j<=w;j++)
			cnt += (s[i][j] == '#');
	
	int x,y;
	x=y=1; fac += (s[1][1] == '#');
	while(x<=h && y<=w)
	{
		if(s[x+1][y] == '#')
			x++,fac++;
		else if(s[x][y+1] == '#')
			y++,fac++;
		else
			break;
	}
	puts(cnt == fac? "Possible":"Impossible");
	return 0;
}