#include<stdio.h>
int main(){
	int n;
	int s[101];
	int i,j;
	int max=0,min=1000000,t=0;
	
	for(;;max=0,min=1000000,t=0){
		scanf("%d",&n);
		if(n==0)break;
		for(i=0;i<n;i++){
			scanf("%d",&s[i]);
			if(s[i]>max)max=s[i];
			if(s[i]<min)min=s[i];
		}
		for(i=0;i<n;i++)t+=s[i];
		t-=(min+max);
		t/=(n-2);
		printf("%d\n",t);
	}
	return 0;
}