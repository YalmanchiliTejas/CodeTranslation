#include<stdio.h>
#include<algorithm>
int main()
{
	int a[5],x,y,i,*p;
	for(;;)
	{
		for(i=0;i<5;++i)
		{
			if(scanf("%d%d",&x,&y),!x&&!y)return 0;
			a[i]=x+y;
		}
		p=std::max_element(a,a+5);
		printf("%c %d\n","ABCDE"[p-a],*p);
	}
}