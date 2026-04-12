#include <stdio.h>
#include <string.h>

int main(void)
{
	int num[6];
	int n, sum, tmp, i;
	char ope[8];
	
	while (scanf("%d", &n) != EOF && n != 0){
		sum = 1;
		for (i = 0; i < 6; i++){
			num[i] = i + 1;
		}
		for (i = 0; i < n; i++){
			scanf("%s", ope);
			if (strcmp(ope, "North") == 0){
				tmp = num[0];
				num[0] = num[1];
				num[1] = num[5];
				num[5] = num[4];
				num[4] = tmp;
				sum += num[0];
			}
			else if (strcmp(ope, "East") == 0){
				tmp = num[0];
				num[0] = num[3];
				num[3] = num[5];
				num[5] = num[2];
				num[2] = tmp;
				sum += num[0];
			}
			else if (strcmp(ope, "West") == 0){
				tmp = num[0];
				num[0] = num[2];
				num[2] = num[5];
				num[5] = num[3];
				num[3] = tmp;
				sum += num[0];
			}
			else if (strcmp(ope, "South") == 0){
				tmp = num[0];
				num[0] = num[4];
				num[4] = num[5];
				num[5] = num[1];
				num[1] = tmp;
				sum += num[0];
			}
			else if (strcmp(ope, "Right") == 0){
				tmp = num[1];
				num[1] = num[2];
				num[2] = num[4];
				num[4] = num[3];
				num[3] = tmp;
				sum += num[0];
			}
			else if (strcmp(ope, "Left") == 0){
				tmp = num[1];
				num[1] = num[3];
				num[3] = num[4];
				num[4] = num[2];
				num[2] = tmp;
				sum += num[0];
			}
		}
		printf("%d\n", sum);
	}
	
	return (0);
}