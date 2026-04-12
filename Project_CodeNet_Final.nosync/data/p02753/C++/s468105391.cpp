#include <stdio.h>

int main(){
	char str[105];
	scanf("%s",str);
	if(str[0]==str[1]&&str[0]==str[2]){
		printf("No\n");
	}
	else{
		printf("Yes\n");
	}
	return 0;
}
