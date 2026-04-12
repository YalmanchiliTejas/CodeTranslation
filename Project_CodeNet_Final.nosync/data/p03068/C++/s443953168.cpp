#include <stdio.h>
int main(void){
  	char str[100] = {0};
  	int n, k;
  	scanf("%d", &n);getchar();
  	fgets(str, 100, stdin);
  	scanf("%d", &k);getchar();
  	for(int i = 0; i < n; i++){
    	if(str[i] != str[k - 1]){
        	str[i] = '*';
        }
    }
  	printf("%s", str);
	return 0;
}