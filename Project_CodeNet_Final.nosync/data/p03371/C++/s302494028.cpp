#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(void)
{	
	int A, B, C, X, Y, a, b, p1, p2, p3;

	scanf("%d", &A);
	scanf("%d", &B);
	scanf("%d", &C);
	scanf("%d", &X);
	scanf("%d", &Y);

	if(X>Y)
	{
		a = 1;
		b = 0;
	}
	else
	{
		a = 0;
		b = 1;
	}

	p1 = A*X + B*Y;
	p2 = 2*C*fmin(X,Y) + (a*A + b*B)*abs(X-Y);
	p3 = 2*C*(fmin(X,Y) + abs(X-Y));

	printf("%d\n", (int)fmin(fmin(p1,p2),p3));
	return 0;
}