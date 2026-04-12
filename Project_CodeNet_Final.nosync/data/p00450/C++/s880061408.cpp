#include<stdio.h>
int b[100000];
int now=0;
bool isBlack;
int color;
int main(){
	int a;
	while(scanf("%d",&a),a){
		now=1;
		int first;
		scanf("%d",&first);
		if(first){
			isBlack=true;
			color=1;
		}else{
			isBlack=false;
			color=0;
		}
		b[0]=0;
		for(int i=1;i<a;i++){
			int val;
			scanf("%d",&val);
			if(i%2==1){
				if(isBlack&&val==0){
					now--;
					isBlack=false;
					if(now==0){
						color=0;
						now++;
					}
				}
				else if(!isBlack&&val==1){
					now--;
					isBlack=true;
					if(now==0){
						color=1;
						now++;
					}
				}
			}else{
				if(isBlack&&val==0){
					b[now++]=i;
					isBlack=false;
				}
				else if(!isBlack&&val==1){
					b[now++]=i;
					isBlack=true;
				}
			}
			//printf("%d %d\n",now,b[now-1]);
		}
		int ret=0;
		b[now++]=a;
		if(color==0){
			for(int i=1;i<now;i+=2)ret+=b[i]-b[i-1];
		}else{
			for(int i=2;i<now;i+=2)ret+=b[i]-b[i-1];
		}
		printf("%d\n",ret);
	}
}