#include <cstdio>
#include <cstring>
int main() {
	int n;
	while(scanf("%d",&n),n) {
		int dice[6]={1,6,4,3,2,5},work[6];
		char query[6];
		int sum=1;
		for(int i=0;i<n;i++) {
			scanf("%s",query);
			if(strcmp(query,"North")==0) {
				work[0]=dice[4];
				work[1]=dice[5];
				work[4]=dice[1];
				work[5]=dice[0];
				work[2]=dice[2];
				work[3]=dice[3];
			}else if(strcmp(query,"South")==0) {
				work[0]=dice[5];
				work[1]=dice[4];
				work[4]=dice[0];
				work[5]=dice[1];
				work[2]=dice[2];
				work[3]=dice[3];
			}else if(strcmp(query,"East")==0) {
				work[0]=dice[2];
				work[1]=dice[3];
				work[2]=dice[1];
				work[3]=dice[0];
				work[4]=dice[4];
				work[5]=dice[5];
			}else if(strcmp(query,"West")==0) {
				work[0]=dice[3];
				work[1]=dice[2];
				work[2]=dice[0];
				work[3]=dice[1];
				work[4]=dice[4];
				work[5]=dice[5];
			}else if(strcmp(query,"Right")==0) {
				work[2]=dice[4];
				work[3]=dice[5];
				work[4]=dice[3];
				work[5]=dice[2];
				work[0]=dice[0];
				work[1]=dice[1];
			}else if(strcmp(query,"Left")==0) {
				work[2]=dice[5];
				work[3]=dice[4];
				work[4]=dice[2];
				work[5]=dice[3];
				work[0]=dice[0];
				work[1]=dice[1];
			}
			for(int i=0;i<6;i++) dice[i]=work[i];
			sum+=dice[0];
		}
		printf("%d\n",sum);
	}
}