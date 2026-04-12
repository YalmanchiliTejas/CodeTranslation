#include<iostream>
#include<cstdio>

using namespace std;

int main(){
	int n;
	while(scanf("%d",&n)){
		if(n==0)
		break;
		int temp,cnt=1;
		int dice[6];
		char com[6];
		dice[0]=5;
		dice[1]=3;
		dice[2]=2;
		dice[3]=4;
		dice[4]=1;
		dice[5]=6;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%s",com);
			if(com[0]=='N'){
				temp=dice[0];
				dice[0]=dice[4];
				dice[4]=dice[2];
				dice[2]=dice[5];
				dice[5]=temp;
				cnt+=dice[4];
			}
			else if(com[0]=='E'){
				temp=dice[1];
				dice[1]=dice[4];
				dice[4]=dice[3];
				dice[3]=dice[5];
				dice[5]=temp;
				cnt+=dice[4];
			}
			else if(com[0]=='W'){
				temp=dice[3];
				dice[3]=dice[4];
				dice[4]=dice[1];
				dice[1]=dice[5];
				dice[5]=temp;
				cnt+=dice[4];
			}
			else if(com[0]=='S'){
				temp=dice[2];
				dice[2]=dice[4];
				dice[4]=dice[0];
				dice[0]=dice[5];
				dice[5]=temp;
				cnt+=dice[4];
			}
			else if(com[0]=='R'){
				temp=dice[2];
				dice[2]=dice[1];
				dice[1]=dice[0];
				dice[0]=dice[3];
				dice[3]=temp;
				cnt+=dice[4];
			}
			else if(com[0]=='L'){
				temp=dice[2];
				dice[2]=dice[3];
				dice[3]=dice[0];
				dice[0]=dice[1];
				dice[1]=temp;
				cnt+=dice[4];
			}
		}
		printf("%d\n",cnt);
	}
}