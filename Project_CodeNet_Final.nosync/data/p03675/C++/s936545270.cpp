#include <bits/stdc++.h>
using namespace std;
int n;
int main (){
	scanf("%d",&n);
	int a[n+5],b[n+5];
	memset(b,0,sizeof(b));
	for (int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int bN=n,j=0;
	while (bN>0)	{
		printf("%d",a[bN-1]);
		bN-=2;
		j++;
		if (j<n)
			printf(" ");
	}
	if (bN%2==0){
		bN=1;
	}
	else {
		bN=2;
	}
	while (bN<n)	{
		printf("%d",a[bN-1]);
		bN+=2;
		j++;
		if (j<n)
			printf(" ");
	}
	return 0;
}