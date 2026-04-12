#include<cstdio>
#include<cstring>
#include<algorithm>
#include<functional>
using namespace std;
int main(void)
{
	int i,j,max=-1,x,flg=0;
	char mise[6]={'A','B','C','D','E'};
	int s1[6],s2[6],sum[6];
	while(1) {
		scanf("%d %d",&s1[0],&s2[0]);
		if(s1[0]==0 && s2[0]==0) {
			break;
		}
		sum[0]=s1[0]+s2[0];
		max=sum[0];
		x=0;
		for(i=1;i<5;i++) {
			scanf("%d %d",&s1[i],&s2[i]);
			sum[i]=s1[i]+s2[i];
			if(max<sum[i]) {
				x=i;
				max=sum[i];
			}
		}
		printf("%c %d\n",mise[x],sum[x]);
		flg=0;
	}
	return 0;
}