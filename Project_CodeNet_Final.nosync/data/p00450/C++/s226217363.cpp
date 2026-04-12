#include<cstdio>
#include<cmath>

using namespace std;

int main(void){
	int n;
	while(scanf("%d", &n) && n != 0){
//		scanf("%d", &n);
		int array[100005]={0};
		int count = 1;
		int temp;
		
		for(int i = 1; i <= n; i++){
			scanf("%d", &temp);
			//ÈçO
			//ÈçPªüÍ³êéB
			
			//Èç³Ì
			//ÈçÌðzñÉ¢êéB
			
			if(i%2){
				if(count > 1 && array[count-1] < 0 && temp == 1)array[count-1]--;
				else if(count > 1 && array[count-1] > 0 && temp == 0)array[count-1]++;
				else if(temp == 0){
					array[count] ++;
					count++;
				}
				else {
					array[count] --;
					count++;
				}
			}else{
				if(temp == 0){
					if(count > 1 && array[count-1] > 0){
						array[count-1]++;
					}else if(count > 2 && array[count-1] < 0){
						array[count-2] += -1*(array[count-1])+1;
						array[count-1] = 0;
						count--;
					}else if(count - 1 > 0 && array[count-1] < 0){
						array[count-1] *= -1;
						array[count-1] ++;
					}
				}else{
					if(count > 1 && array[count-1] < 0){
						array[count-1]--;
					}else if(count > 2 && array[count-1] > 0){
						array[count-2] += -1*(array[count-1]+1);
						array[count-1] = 0;
						count--;
					}else if(count > 1 && array[count-1] > 0){
						array[count-1] *= -1;
						array[count-1] --;
					}
				}
			}
			/*
			printf("count -> %d\n",count);
			for(int i = 0; i <= count ; i++){
				printf("%d%s",array[i],i>=0?" ":"");
			}puts("");
			*//*
			for(int i = 1; i < count; i++){
				for(int j = 0; j < abs(array[i]); j++){
					printf("%s", array[i]>0?"":"");
				}
			}puts("");
			//*/
		}
		int ans = 0;
		for(int i = 0; i <= count; i++){
			if(array[i] > 0)ans+=array[i];
		}
		printf("%d\n",ans);
	}
	
	return 0;
}