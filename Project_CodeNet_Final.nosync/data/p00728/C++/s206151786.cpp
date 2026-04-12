#include <stdio.h>

int main(){
    int n,s[100]={0};
	int max,min,max1,min1;
	int sum,i;

scanf("%d",&n);

do{
	max=0;
	min=100000;
	sum=0;
	sum=0;
    max1=0;
    min1=0;
	for (i=0;i<n;i++){
		scanf("%d",&s[i]);
		if(s[i]>max){
            max=s[i];
			max1=i;
		}
		if(s[i]<min){
			min=s[i];
            min1=i;
		}
	}
	for(i=0;i<n;i++){
		if(i!=max1&&i!=min1){
			sum+=s[i];
		}
	}
	printf("%d\n",sum/(n-2));
	scanf("%d",&n);
}while (n!=0);
return 0;
}