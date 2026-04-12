#include<cstdio>
#include<cstring>
using namespace std;
int main(void)
{
	char migi[12]="yuiophjklnm";
	int len,i,j,cnt,flg,m;
	char buf[33];
	while(1)	{
		scanf("%s",buf);
		if(buf[0]=='#')	break;
		len=strlen(buf);
		m=0;
		for(j=0;j<11;j++)	{
			if(buf[0]==migi[j])	{
				m=1;
				break;
			}
		}
		cnt=0;
		for(i=1;i<len;i++)	{
			flg=0;
			for(j=0;j<11;j++)	{
				if(buf[i]==migi[j])	{
					flg=1;
					break;
				}
			}
			if(m!=flg)	{
				cnt++;
				m=flg;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
