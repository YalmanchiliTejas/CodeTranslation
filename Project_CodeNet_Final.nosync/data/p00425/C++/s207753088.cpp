#include <stdio.h>
#include <string.h>

int main(void)
{
	int i;
	int n, e, w, s, t;
	int tmp;
	char str[16];
	int total;
	
	while (scanf("%d", &n), n != 0){
		t = 1;
		s = 2;
		e = 3;
		
		total = 1;
		for (i = 0; i < n; i++){
			scanf("%s", str);
			if (strcmp(str, "North") == 0){
				tmp = s;
				s = 7 - t;
				t = tmp;
			}
			if (strcmp(str, "East") == 0){
				tmp = e;
				e = t;
				t = 7 - tmp;
			}
			if (strcmp(str, "West") == 0){
				tmp = e;
				e = 7 - t;
				t = tmp;
			}
			if (strcmp(str, "South") == 0){
				tmp = s;
				s = t;
				t = 7 - tmp;
			}
			if (strcmp(str, "Right") == 0){
				tmp = s;
				s = e;
				e = 7 - tmp;
			}
			if (strcmp(str, "Left") == 0){
				tmp = e;
				e = s;
				s = 7 - tmp;
			}
			total += t;
		}
		printf("%d\n", total);
	}
	return (0);
}