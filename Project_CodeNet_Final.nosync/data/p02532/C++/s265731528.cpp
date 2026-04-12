#include <stdio.h>
#include <string.h>

int main(void){
	char cmd[10];
	char color;
	int moun,moun2;
	char stack[1000][100];
	char temp_c;
	int temp;
	int num[1000];
	int i;

	scanf("%d",&i);
	while(1){
		fscanf(stdin,"%s",cmd);
		if(strcmp(cmd,"push") == 0){
			fscanf(stdin," %d %c",&moun,&color);
			stack[num[moun]][moun] = color;
			num[moun]++;			
		}else if(strcmp(cmd,"pop") == 0){
			fscanf(stdin," %d",&moun);
			num[moun]--;
			printf("%c\n",stack[num[moun]][moun]);
		}else if(strcmp(cmd,"move") == 0){
			fscanf(stdin," %d %d",&moun,&moun2);
			num[moun]--;
			temp_c = stack[num[moun]][moun];
			stack[num[moun2]][moun2] = temp_c;
			num[moun2]++;
		}else if(strcmp(cmd,"quit") == 0)
			break;
	}
	return 0;
}