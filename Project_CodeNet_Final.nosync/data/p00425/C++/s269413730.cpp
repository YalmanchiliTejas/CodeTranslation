#include<stdio.h>
void move(int,int);
int m[6];
int main(){
	int n,i,cnt=1;
	char p[10];
	while(1){
		scanf("%d",&n);
		if(n==0){
			break;
		}
		cnt=1;
		for(i=0;i<6;i++){
			m[i]=i+1;
		}
		for(i=0;i<n;i++){
			scanf("%s",p);
			if(p[0]=='N'){
				move(0,1);
			}
			else if(p[0]=='E'){
					move(0,3);
			}
			else if(p[0]=='W'){
				move(0,2);
			}
			else if(p[0]=='S'){
				move(0,4);
			}
			else if(p[0]=='R'){
				move(1,2);
			}
			else{
				move(1,3);
			}
			cnt+=m[0];
		}
		printf("%d\n",cnt);
	}
	return 0;
}
void move(int a,int b)
{
	int temp;
	temp=m[a];
	m[a]=m[b];
	m[b]=m[5-a];
	m[5-a]=m[5-b];
	m[5-b]=temp;
}