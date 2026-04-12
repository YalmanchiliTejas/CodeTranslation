#include<bits/stdc++.h>
using namespace std;
int main()
{
	int x, n, y, z=0, i, t;
	scanf("%d", &n);
	z=800*n;
	if(n>15){
		i=n/15;
		t=z-(i*200);
		printf("%d", t);
	}
	else{
		printf("%d", z);
	}
	return 0;
}