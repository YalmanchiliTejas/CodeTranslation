#include <stdio.h>
#include <string.h>

int main(void){
	int i, j, point[1001], n, s, sum, cnt;
	scanf("%d",&n);
	while(n != 0){
		memset(point,0,sizeof(point));
		for(i = 0;i < n;i++){
			scanf("%d",&s);
			point[s]++;
		}
		for(i = 0;i <= 1000;i++){
			if(point[i]){
				point[i]--;
				break;
			}
		}
		for(i = 1000;i >= 0;i--){
			if(point[i]){
				point[i]--;
				break;
			}
		}
		sum = 0;
		cnt = 0;
		for(i = 0;i <= 1000;i++){
			for(j = 0;j < point[i];j++){
				sum += i;
				cnt++;
			}
		}
		printf("%d\n",sum / cnt);
		scanf("%d",&n);
	}
	return 0;
}