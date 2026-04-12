#include <stdio.h>

int main(void)
{
	int x,y,z,c,d,a[100][100],b[100][100];
	scanf("%d %d",&c,&d);
	char i[100];
	for(x=0;x<c;x++) for(y=0;y<d;y++) b[x][y] = 0;
	for(x=0;x<c;x++)
	{
		scanf("%s",i);
		for(y = 0;y<d;y++)
		{
			if (i[y] == '#') a[x][y] = 1;
			else a[x][y] = 0;
		}
	}
	for(x=0;x<c;x++)
	{
		for(y = 0;y<d;y++)
		{
			if (a[x][y] == 1) 
			{
				for(z=0;z<d;z++) b[x][z] = 1;
				y = d;
			}
		}
		
	}
	for(y = 0;y<d;y++)
	{
		for(x=0;x<c;x++)
		{
			if (a[x][y] == 1)break;
		}
		if (x==c)
		{
			for(z=0;z<c;z++) b[z][y] = 0;
		}
	}
	int ind;
	for(x=0;x<c;x++) 
	{
		ind = 0;
		for(y=0;y<d;y++) {
			if (b[x][y]) 
			{
				if(a[x][y]) printf("#"); 
				else printf(".");
				ind = 1;
			}
		}
		if (ind) puts("");
	}
	return 0;
}
