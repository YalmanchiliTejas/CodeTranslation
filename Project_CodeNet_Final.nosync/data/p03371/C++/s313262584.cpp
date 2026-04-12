#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>

#define SIZE 100

int data[SIZE];
char line[SIZE];

int A,B,C,X,Y,Z;
int bill1,bill2,bill3;
int bill;
int min;
int max;
int main(){
#ifdef DEBUG
	printf("DEBUGGING ON\n");
#endif
	fgets(line,sizeof(line),stdin);
	sscanf(line,"%d %d %d %d %d",&A,&B,&C,&X,&Y);
	min = X;
	max = Y;
	if (min > Y){ min = Y;max = X;}
	/* bill = A*(X-Z/2)+B*(Y-Z/2)+C*Z */
	bill1 = A*(X-0/2)+B*(Y-0/2)+C*0;
	bill2 = A*(X-min)+B*(Y-min)+2*C*min;
	bill3 = A*(X-X)+B*(Y-Y)+2*C*max;
	bill = bill1;
	if (bill>bill2) bill=bill2;
	if (bill > bill3) bill = bill3;
	printf("%d\n",bill);
	return 0;
}