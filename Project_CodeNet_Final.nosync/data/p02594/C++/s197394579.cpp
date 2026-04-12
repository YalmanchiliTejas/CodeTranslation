#include<stdio.h>
int main(){
	int temperature;
	scanf("%d", &temperature);
	if(temperature >= 30){
		printf("Yes");
	}
	if(temperature <30){
		printf("No");
	}
	return 0;
}