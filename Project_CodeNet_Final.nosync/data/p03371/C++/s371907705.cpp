#include<stdio.h>
#include<string.h>
using namespace std;

int f_min(int a, int b){
	return a > b ? b : a;
}

int f_max(int a, int b){
	return a < b ? b : a;
}

int main(){
	int A, B, C, X, Y, ans;
	scanf("%d %d %d %d %d", &A, &B, &C, &X, &Y);
	
	int op1 = X*A + Y*B;
	int op2 = 2*C*f_max(X, Y);
	int op3;
	if(X>Y){
		op3 = 2*C*Y + ((X-Y)*A);
	} else op3 = 2*C*X + ((Y-X)*B);


	ans = f_min(f_min(op1, op2), op3);
	printf("%d\n", ans);
}