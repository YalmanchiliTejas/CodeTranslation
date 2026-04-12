#include <stdio.h>
#include <string.h>
using namespace std;

int main(){
	int check,count;
	int n;
	scanf("%d",&n);
	double h[n+1];

	for(int i=1;i<=n;i++){
		scanf("%lf",&h[i]);
	}
	count=1;
	for(int i=2;i<=n;i++){
		check=0;
		for(int j=1; j<i; j++){
			if(h[j]>h[i]) check=1;
		}
		if(check==0) count++;
	}
	printf("%d",count);
	return 0;
}
