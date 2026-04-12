#include<stdio.h>
int main()
{
	int A, B, C, X, Y;
	int price = 0;
	int amount = 0;

	scanf("%d %d %d %d %d", &A, &B, &C, &X, &Y);

	int minor, major;
	int cost;
	if (X > Y)
	{
		minor = Y;
		major = X;
		cost = A;
	}
	else
	{
		minor = X;
		major = Y;
		cost = B;
	}
	//	better to combine
	if (cost>2*C)
	{
		price = 2 * major*C;
	}
	else if (A+B>=2*C)
	{
		//printf("combine better\n");
		while (amount<minor)
		{
			amount++;
			price += 2 * C;
		}
		while (amount<major)
		{
			amount++;
			price += cost;
		}
	}
	else
	{
		//printf("separate better\n");
		price += A*X + B*Y;
	}
	printf("%d", price);
	return 0;
}