#include<bits/stdc++.h>
using namespace std;
int main()
{
	int x, n, y, i;
	scanf("%d", &n);
	if(n>=1 && n<=100){
			x=800*n;
		if(n>15){
			i=n/15;
			y=(i*200);
			printf("%d", x-y);
		}
		else{
			printf("%d", x);
		}
	}
	else{
		printf("Error");
	}
	return 0;
}