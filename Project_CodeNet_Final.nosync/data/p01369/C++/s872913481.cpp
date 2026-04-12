#include <stdio.h>

int main(void){
	int i, j, before, count;
	char c, r[12] = {"yuiophjklnm"}, l[16] = {"qwertasdfgzxcvb"};
	while(1){
		c = getchar();
		if(c != '#'){
			for(i = 0;i < 11;i++)
				if(c == r[i]) break;
			for(j = 0;j < 15;j++)
				if(c == l[j]) break;
			if(i == 11)
				before = 0;
			else if(j == 15)
				before = 1;
			count = 0;
			while((c = getchar()) != '\n'){
				for(i = 0;i < 11;i++)
					if(c == r[i]) break;
				for(j = 0;j < 15;j++)
					if(c == l[j]) break;
				if(i == 11 && before == 1){
					count++;
					before = 0;
				}else if(j == 15 && before == 0){
					count++;
					before = 1;
				}
			}
		}
		else
			break;
		printf("%d\n",count);
	}
	return 0;
}