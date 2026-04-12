#include<stdio.h>
int main(){
int x,y,z;
scanf("%d %d %d",&x,&y,&z);
int n=1;
x=x-y-2*z;
while(x>=y+z){
	x=x-y-z;
	n++;

	

}

printf("%d\n",n);
}