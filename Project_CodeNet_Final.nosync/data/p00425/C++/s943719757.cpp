#include <cstdio>

char opr[10];
int top=1,front=2,right=3,n=0,sum=1,swap;

int dice(int n){
	//scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",opr);
		switch (opr[0]){
		case 'N':
			swap=top;
			top=front;
			front=(7-swap);
			break;
		case 'E':
			swap=right;
			right=top;
			top=(7-swap);
			break;
		case 'W':
			swap=top;
			top=right;
			right=(7-swap);
			break;
		case 'S':
			swap=front;
			front=top;
			top=(7-swap);
			break;
		case 'R':
			swap=front;
			front=right;
			right=(7-swap);
			break;
		case 'L':
			swap=right;
			right=front;
			front=(7-swap);
			break;

		}
		sum+=top;
	}
	if(n!=0) printf("%d\n",sum);
	//int top=1,front=2,right=3,sum=1,swap;
	return 0;
}

int main(){
	while(1) {
	scanf("%d",&n); 
	dice(n);
	top=1,front=2,right=3,sum=1,swap;
	if(n==0) break;
	}
	return 0;
}