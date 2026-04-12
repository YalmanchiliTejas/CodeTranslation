#include<cstdio>

int main(void)
{
	int m;
	int i,j,k;
	int first,year,kind;
	int tanhuku,tesuu;
	double nenri;
	int a,b,sum,temp;
	int max=0;
	
	for(;;)
	{
		scanf("%d", &m);
		for(i=0; i<m; i++)
		{
			scanf("%d",&first);
			scanf("%d",&year);
			scanf("%d",&kind);
			max=0;
			for(j=0; j<kind; j++)
			{
				scanf("%d %lf %d",&tanhuku,&nenri,&tesuu);
				a=first,b=0,sum=0,temp=0;
				for(k=0; k<year; k++)
				{
					if(tanhuku==1) //複利
					{
						b=a*nenri;
						sum=a+b-tesuu;
						a=sum;
					}
					else //単利
					{
						b=a*nenri;
						sum=a-tesuu;
						a=sum;
						temp+=b;
						if(k==year-1)
						{
							sum+=temp;
						}
					}
				}
				if(sum>max) max=sum;
			}
			printf("%d\n",max);
		}
		if(i==m) break;
	}
	
	return 0;
}