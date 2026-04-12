#include<stdio.h>

int main(){
	int A=0;
	int B=0;
	int C=0;
	int X=0;
	int Y=0;
	scanf("%d %d %d %d %d",&A,&B,&C,&X,&Y);
	int C_MAX=2*(X+Y);
	int min_val=0;
	for(int c=0;c<=C_MAX;c++){
		int val=0;
		int a=0;
		int b=0;
		//C
		a=c/2;
		b=c/2;
		val+=C*c;
		//A
		while(X>a){
			val+=A;
			a++;
		}
		//B
		while(Y>b){
			val+=B;
			b++;
		}
		
		if((val<min_val) || (c==0)){
			min_val=val;
		}
	}
	printf("%d\n",min_val);
}