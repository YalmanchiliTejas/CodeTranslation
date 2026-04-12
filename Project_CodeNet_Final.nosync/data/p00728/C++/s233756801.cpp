#include<stdio.h>

int main(){
	int loop = 0;
	int i,buf;
	while(true){
		scanf("%d",&loop);
		if(loop == 0){
			break;
		}
		int max = -1;
		int min = 1000;
		int ans = 0;
		for(i=0;i<loop;i++){
			scanf("%d",&buf);
			if(max < buf){
				max = buf;
			}
			if(min > buf){
				min = buf;
			}
			ans += buf;
		}
		ans -= (max + min);
		printf("%d\n",ans/(loop-2));
	}
}