#include<cstdio>
#include<cstring>
using namespace std;

int main(void)
{
	int m,n,i,j;
	char s[10001][100];
	int pl[1001],flg;
	int p,sum,cnt,f,nn;
	
	while(1)	{
		scanf("%d %d",&m,&n);
		if(m==0 && n==0)	break;
		for(i=1;i<=n;i++)	scanf("%s",s[i]);
		for(i=1;i<=m;i++)	pl[i]=i;
		p=1;	
		cnt=m;
		for(i=1;i<=n;i++)	{
			flg=1;
			if(i%15==0)	{
				if(strcmp(s[i],"FizzBuzz")!=0)	{
					flg=0;	cnt--;
				}
			}
			else if(i%3==0)	{
				if(strcmp(s[i],"Fizz")!=0)	{
//					printf("p=%d pl=%d\n",p,pl[p]);
					flg=0;	cnt--;
				}
			}
			else if(i%5==0)	{
				if(strcmp(s[i],"Buzz")!=0)	{
//					printf("p=%d pl=%d\n",p,pl[p]);				
					flg=0;	cnt--;
				}
			}
			else {
				nn=strlen(s[i]);
				sum=0;
				for(j=0;j<nn;j++)	{
					sum*=10;
					sum+=s[i][j]-'0';
				}
//				printf("sum=%d\n",sum);
				if(sum!=i)	{
					flg=0;	cnt--;
//					printf("ccc\n");
				}
			}
			if(flg==0)	{
				for(j=p;j<=cnt;j++)	{
					pl[j]=pl[j+1];
//					printf("pl=%d \n",pl[j]);
				}
			}
			else {
				p++;
			}
			if(p>cnt)	p=1;	
			if(cnt==1)	break;
		}
		f=1;
		for(i=1;i<=cnt;i++)	{
			if(f==1)	{
				printf("%d",pl[i]);
				f=0;
			}
			else {
				printf(" %d",pl[i]);
			}
		}
		printf("\n");
	}
	return 0;
}
