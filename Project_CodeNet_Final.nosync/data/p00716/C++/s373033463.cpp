#include<stdio.h>
int main()
{
	int m,a,y,n,s,t,b,_,dy,da;
	double r;
	scanf("%d",&m);
	while(m--)
	{
		s=0;
		scanf("%d%d%d",&a,&y,&n);
		while(n--)
		{
			da=a,dy=y;
			scanf("%d%lf%d",&t,&r,&b);
			if(t)while(dy--)da=da*(1+r)-b;
			else 
			{
				_=0;
				while(dy--)_+=da*r,da-=b;
				da+=_;
			}
			s=(s>da?s:da);
		}
		printf("%d\n",s);
	}
	return 0;
}