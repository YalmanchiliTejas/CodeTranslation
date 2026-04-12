#include<cstdio>

int main(){
	int A, B, C, X, Y;
	scanf("%d %d %d %d %d", &A, &B, &C, &X, &Y);
	if(C*2 >= A + B){
		printf("%d\n", A*X + B*Y);
		return 0;
	}
	if(X >= Y){
		if(C*2 >= A){
			printf("%d\n", C*Y*2 + A*(X - Y));
			return 0;
		}
		printf("%d\n", C*X*2);
		return 0;
	}
 	if(C*2 >= B){
		printf("%d\n", C*X*2 + B*(Y - X));
		return 0;
	}
	printf("%d\n", C*Y*2);
	return 0;
}