/* 
	Author: ankrypt
*/
#include <bits/stdc++.h>

using namespace std;

long long A, B, C, X, Y;
long long price;

int main()
{
	scanf("%lld %lld %lld %lld %lld", &A, &B, &C, &X, &Y);
	long long tempAns1 = (X * A) + (Y * B);
	long long tempAns2 = 2 * max(X, Y) * C;
	long long tempAns3 = 2 * min(X, Y) * C;
	if(max(X, Y) == X) {
		tempAns3 += (X - Y) * A;
	}
	else
	{
		tempAns3 += (Y - X) * B; 
	}
	// cerr << tempAns1 << " " << tempAns2 << " " << tempAns3 << " ";
	long long finalAns = min(tempAns1, min(tempAns3, tempAns2));
	printf("%lld\n", finalAns);
	
	return 0;
}
/*
	Powered by Buggy Plugin
*/
