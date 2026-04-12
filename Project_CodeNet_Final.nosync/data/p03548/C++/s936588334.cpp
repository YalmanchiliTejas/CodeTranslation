#include<stdio.h>
int main(){
int x,y,z;
int n,r;

scanf("%d%d%d",&x,&y,&z);
n = x/(y+z);
r = x%(y+z);
if(r>=z){
	printf("%d\n",n);
}else{
	printf("%d\n",n-1);

}
return 0;
}