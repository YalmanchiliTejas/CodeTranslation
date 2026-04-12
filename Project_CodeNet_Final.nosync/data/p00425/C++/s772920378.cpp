#include <stdio.h>
#include <string.h>

int main(void)
{
	int dice[7];
	char str_o[6][7] = {"North", "East", "West", "South", "Right", "Left"};
	char str[7];
	int order;
	int num;
	int sum;
	int dice_n;
	int i;
	
	while (1){
		scanf("%d", &num);
		if (num == 0){
			break;
		}
		
		for (i = 0; i <= 6; i++){
			dice[i] = i;
		}
		
		sum = dice[1];
		while (num){
			scanf("%s", str);
			
			for (i = 0; i < 6; i++){
				if (!strcmp(str_o[i], str)){
					order = i + 1;
					break;
				}
			}
			
			switch (order){
				case 1:
				dice[0] = dice[1];
				dice[1] = dice[2];
				dice[2] = dice[6];
				dice[6] = dice[5];
				dice[5] = dice[0];
				break;
				
				case 2:
				dice[0] = dice[1];
				dice[1] = dice[4];
				dice[4] = dice[6];
				dice[6] = dice[3];
				dice[3] = dice[0];
				break;
				
				case 3:
				dice[0] = dice[1];
				dice[1] = dice[3];
				dice[3] = dice[6];
				dice[6] = dice[4];
				dice[4] = dice[0];
				break;
				
				case 4:
				dice[0] = dice[1];
				dice[1] = dice[5];
				dice[5] = dice[6];
				dice[6] = dice[2];
				dice[2] = dice[0];
				break;
				
				case 5:
				dice[0] = dice[2];
				dice[2] = dice[3];
				dice[3] = dice[5];
				dice[5] = dice[4];
				dice[4] = dice[0];
				break;
				
				case 6:
				dice[0] = dice[2];
				dice[2] = dice[4];
				dice[4] = dice[5];
				dice[5] = dice[3];
				dice[3] = dice[0];
				break;
			}
			
			sum += dice[1];
			
			num--;
		}
		printf("%d\n", sum);
	}
	
	return (0);
}