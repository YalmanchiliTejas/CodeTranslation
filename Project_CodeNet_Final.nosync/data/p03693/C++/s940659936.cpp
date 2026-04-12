#include <stdio.h>;

int main() {
	int r,g,b,res;
	scanf("%d%d%d",&r,&g,&b);
	res=100*r+10*g+b;
	if(res%4==0){
		printf("YES");
	}
	else{
		printf("NO");
	}

return 0;
}
