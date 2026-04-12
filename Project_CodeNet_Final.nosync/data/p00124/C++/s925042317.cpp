#include<stdio.h>
#include<string.h>
int main(void)
{
	int n,i,j;
	int temp,data[10];
	char tn[11][21],temps[21];
	int k,m,h;
	scanf("%d" ,&n);
	while(n!=0){
		for(j=0;j<10;j++){
			data[j]=0;
		}
		for(j=0;j<n;j++){
			scanf("%s %d %d %d",tn[j],&k,&m,&h);
			data[j]+=k*3;
			data[j]+=h;
		}
		for(i=0;i<n-1;i++){
			for(j=n-1;j>i;j--){
				if(data[j]>data[j-1]){
					temp=data[j];
					data[j]=data[j-1];
					data[j-1]=temp;
					strcpy(temps,tn[j]);
					strcpy(tn[j],tn[j-1]);
					strcpy(tn[j-1],temps);
				}
			}
		}
		for(j=0;j<n;j++){
				printf("%s,%d\n",tn[j],data[j]);
		}
		scanf("%d",&n);
		if(n!=0){
			printf("\n");
		}
	}
	return 0;
}