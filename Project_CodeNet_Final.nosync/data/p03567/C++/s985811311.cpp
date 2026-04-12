#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>


char str[10];

int main()
{
	int i, len;
	scanf("%s", str);
	len = strlen(str);
	
	for(i = 0; i < len; i++){
		if(str[i] == 'A' && str[i + 1] == 'C') break;
	}
	if(i == len){
		printf("No\n");
	}
	else{
		printf("Yes\n");
	}
	
	return 0;


}