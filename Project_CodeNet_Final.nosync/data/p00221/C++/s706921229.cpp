#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void make_pat(int count, char pat[])
{
	int d = 0;
	
	pat[0] = '\0';
	if (count % 3 == 0){
		d = 1;
		strcat(pat, "Fizz");
	}
	if (count % 5 == 0){
		d = 1;
		strcat(pat, "Buzz");
	}
	if (d == 0){
		sprintf(pat, "%d", count);
	}
}

int main(void)
{
	int n; // ­¾ñ
	int m; // lÌ
	int butt;
	int out[1000];
	char flag[1000];
	char in[100];
	char pat[100];
	
	while (1){
		memset(flag, 1, 1000);
		
		scanf("%d%d", &m, &n);
		if (m == 0 || n == 0){
			break;
		}
		
		butt = m;
		int check = 0;
		for (int i = 0; i < n; i++){
			scanf("%s", in);
			
			if (butt == 1){
				continue;
			}
			
			while (flag[check] == 0){
				check = (check + 1) % m;
			}
			
			make_pat(i + 1, pat);
			if (strcmp(pat, in) != 0){
				flag[check] = 0;
				butt--;
			}
			check = (check + 1) % m;
		}
		
		int count = 0;
		for (int i = 0; i < m; i++){
			if (flag[i] == 1){
				out[count++] = i + 1;
			}
		}
		
		printf("%d", out[0]);
		for (int i = 1; i < count; i++){
			printf(" %d", out[i]);
		}
		
		puts("");
	}
	
	return (0);
}