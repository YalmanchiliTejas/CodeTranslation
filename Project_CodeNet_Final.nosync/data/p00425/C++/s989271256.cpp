#include <stdio.h>
#include <string.h>

int main(){
	while(1){

	int n;
	scanf("%d", &n);
	if(n==0)break;

	int i;
	char order[10];
	int k=1;

	int data[] = {1,2,3,4,5,6};
	int d[6];
	for(i=0;i<n;i++){
		for(int j=0;j<6;j++) d[j] = data[j];
		scanf(" %s", order);
		if(!strcmp(order, "North")){
			int t[] = {1,5,2,3,0,4};
			for(int j=0;j<6;j++) data[j] = d[t[j]];
		}else if(!strcmp(order, "East")){
			int t[] = {3,1,0,5,4,2};
			for(int j=0;j<6;j++) data[j] = d[t[j]];
		}else if(!strcmp(order, "West")){
			int t[] = {2,1,5,0,4,3};
			for(int j=0;j<6;j++) data[j] = d[t[j]];
		}else if(!strcmp(order, "South")){
			int t[] = {4,0,2,3,5,1};
			for(int j=0;j<6;j++) data[j] = d[t[j]];
		}else if(!strcmp(order, "Left")){
			int t[] = {0,3,1,4,2,5};
			for(int j=0;j<6;j++) data[j] = d[t[j]];
		}else{
			int t[] = {0,2,4,1,3,5};
			for(int j=0;j<6;j++) data[j] = d[t[j]];
		}
		k += data[0];
	}

	printf("%d\n", k);
	}
}