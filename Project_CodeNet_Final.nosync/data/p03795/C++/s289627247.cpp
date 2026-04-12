#include<bits/stdc++.h>
using namespace std;
int main()
{
	int x, n, y, z=0, i, t;
	scanf("%d", &n);
	if(n>=1 && n<=100){
			z=800*n;
		if(n>15){
			i=n/15;
			t=z-(i*200);
			printf("%d", t);
		}
		else{
			printf("%d", z);
		}
	}
	else{
		printf("Error");
	}
	return 0;
}