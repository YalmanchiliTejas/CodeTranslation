#include<stdio.h>
int main()
{
	char r[5]={'A','B','C','D','E'};
	int s1[5],i,s2[5],m=0,l;
	while(1){
		for(i=0;i<5;i++){
			scanf("%d%d",&s1[i],&s2[i]);
			if(s1[i]==0&&s2[i]==0){
				return 0;
			}
		}
		for(i=0;i<5;i++){
			if(m<s1[i]+s2[i]){
				m=s1[i]+s2[i];
				l=i;
			}
		}
		printf("%c %d\n",r[l],m);
		m=0;
	}
	return 0;
}