#include <stdio.h>
int a,b,c,x,y;
int ans1,ans2,ans3;
int min(int a,int b){
	return a<b?a:b;
}
int main(){
	scanf("%d %d %d %d %d",&a,&b,&c,&x,&y);
	ans1 = x > y ? 2*c*y+(x-y)*a : 2*c*x+(y-x)*b;
	ans2 = a*x+b*y;
	ans3 = x>y?2*c*x:2*c*y;
	printf("%d",min(min(ans1,ans2),ans3));
}