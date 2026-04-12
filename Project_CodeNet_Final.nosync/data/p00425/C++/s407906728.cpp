#include<stdio.h>
#include<string.h>
int n;
int ans;
int d[6];
char ord[5];
int m;

int main(){
	while(true){
		scanf("%d",&n);
		if(n==0)break;
		ans=1;
		d[0]=6;d[1]=1;d[2]=4;d[3]=3;d[4]=5;d[5]=2;
		for(int i=0;i<n;i++){
			scanf("%s",&ord);
			if(strcmp(ord,"North")==0)m=0;
			if(strcmp(ord,"South")==0)m=1;
			if(strcmp(ord,"East")==0)m=2;
			if(strcmp(ord,"West")==0)m=3;
			if(strcmp(ord,"Right")==0)m=4;
			if(strcmp(ord,"Left")==0)m=5;
			switch(m){
			case 0:
				d[0]=d[4];
				d[4]=d[1];
				break;
			case 1:
				d[4]=d[0];
				d[0]=d[5];
				break;
			case 2:
				d[2]=d[0];
				d[0]=d[3];
				break;
			case 3:
				d[0]=d[2];
				d[2]=d[1];
				break;
			case 4:
				d[4]=d[2];
				d[2]=d[5];
				break;
			case 5:
				d[2]=d[4];
				d[4]=d[3];
				break;
			}
			d[1]=7-d[0];
			d[3]=7-d[2];
			d[5]=7-d[4];
			ans+=d[1];
		}
		printf("%d\n",ans);
	}
}