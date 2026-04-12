#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>




int main()
{

	int i;
	int z; //左は１、右は０
	char a[33];
	int ans;

	while(1)
	{
		scanf("%s",a);
		if(a[0]=='#'){break;}
		else
		{
			ans=0;
			for(i=0;i<strlen(a);i++)
			{
				if(i==0)
				{
					if((a[i]=='y')||(a[i]=='u')||(a[i]=='i')||(a[i]=='o')||(a[i]=='p')||(a[i]=='h')||(a[i]=='j')||(a[i]=='k')||(a[i]=='l')||(a[i]=='n')||(a[i]=='m'))
					{
						z=0;
					}else
					{
						z=1;
					}
				}else
				{
					if(z==0)
					{
						if((a[i]=='y')||(a[i]=='u')||(a[i]=='i')||(a[i]=='o')||(a[i]=='p')||(a[i]=='h')||(a[i]=='j')||(a[i]=='k')||(a[i]=='l')||(a[i]=='n')||(a[i]=='m')){}
						else{z=1;ans++;}
					}else
					{
						if((a[i]=='y')||(a[i]=='u')||(a[i]=='i')||(a[i]=='o')||(a[i]=='p')||(a[i]=='h')||(a[i]=='j')||(a[i]=='k')||(a[i]=='l')||(a[i]=='n')||(a[i]=='m'))
						{z=0;ans++;}
					}
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
	