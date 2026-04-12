#include<stdio.h>
#include<algorithm>
int main()
{
	int n[6],n1,n2,n3,i,j,r;
	for(;;)
	{
		j=0;
		for(i=0;i<6;++i)
		{
			scanf("%d",&n[i]);
			j+=n[i];
		}
		if(!j)return 0;
		n1=n[0]+n[3];
		n2=n[1]+n[4];
		n3=n[2]+n[5];
		r=0;
		while(n1>0 && n2>0 && n3>0)
		{
			int a[3] = {n1%3,n2%3,n3%3};
			std::sort(a,a+3);
			if( (a[0]==a[1]||a[1]==a[2])	&&a[1]>0) 
			{
				++r;
				--n1,--n2,--n3;
			}
			else break;
		}
		r+= n1/3 + n2/3 + n3/3;
		printf("%d\n",r);
	}
}