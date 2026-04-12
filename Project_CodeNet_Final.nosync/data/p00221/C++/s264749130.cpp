#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int m, n;
	
	while (scanf("%d %d", &m, &n), m + n){
		bool flag[2048] = {false};
		int p = 0;
		int cnt = 0;
		for (int i = 1; i <= n; i++){
			char str[128];
			scanf("%s", str);
			
			if (cnt < m - 1){
				char str2[128];
				if (i % 15 == 0){
					strcpy(str2, "FizzBuzz");
				}
				else if (i % 3 == 0){
					strcpy(str2, "Fizz");
				}
				else if (i % 5 == 0){
					strcpy(str2, "Buzz");
				}
				else {
					sprintf(str2, "%d", i);
				}
				
				if (strcmp(str, str2) != 0){
					flag[p % m] = true;
					cnt++;
				}
				while (1){
					p++;
					if (flag[p % m] == false){
						break;
					}
				}
			}
		}
		
		bool f = false;
		for (int i = 0; i < m; i++){
			if (flag[i] == false){
				if (f){
					printf(" ");
				}
				printf("%d", i + 1);
				f = true;
			}
		}
		puts("");
	}
	
	return 0;
}