#include <stdio.h>
#include <string.h>

int main(void) {
	int sum, n, i,buf[6],cs[6] = {1,5,6,2,3,4}, ci[6];
	char way[6]; 
	while(scanf("%d",&n)){
		if(n == 0)break;
		sum = 1;
		memcpy(ci, cs, sizeof(ci));
	for(i = 0; n > i; i++){
		scanf("%s",way);
		if(!strcmp(way, "North")){
			buf[0] = ci[3];
			buf[1] = ci[0];
			buf[2] = ci[1];
			buf[3] = ci[2];
			buf[4] = ci[4];
			buf[5] = ci[5];
		}
		else if(!strcmp(way, "East")){
			buf[0] = ci[5];
			buf[1] = ci[1];
			buf[2] = ci[4];
			buf[3] = ci[3];
			buf[4] = ci[0];
			buf[5] = ci[2];
		}
		else if(!strcmp(way, "South")){
			buf[0] = ci[1];
			buf[1] = ci[2];
			buf[2] = ci[3];
			buf[3] = ci[0];
			buf[4] = ci[4];
			buf[5] = ci[5];
		}
		else if(!strcmp(way, "West")){
			buf[0] = ci[4];
			buf[1] = ci[1];
			buf[2] = ci[5];
			buf[3] = ci[3];
			buf[4] = ci[2];
			buf[5] = ci[0];
		}
		else if(!strcmp(way, "Right")){
			buf[0] = ci[0];
			buf[1] = ci[5];
			buf[2] = ci[2];
			buf[3] = ci[4];
			buf[4] = ci[1];
			buf[5] = ci[3];
		}
		else if(!strcmp(way, "Left")){
			buf[0] = ci[0];
			buf[1] = ci[4];
			buf[2] = ci[2];
			buf[3] = ci[5];
			buf[4] = ci[3];
			buf[5] = ci[1];
		}
		sum += buf[0];
		memcpy(ci, buf, sizeof(ci));
	}
	printf("%d\n",sum);
	}
	return 0;
}