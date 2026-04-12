#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int n[2][50],p=0,temp,dd,bb=1;
	while(1){
		scanf("%d,%d",&n[0][p],&n[1][p]);
		if(n[0][p]==0&&n[1][p]==0)break;
		p++;
	}	
	for(int i=0;i<p;i++){
		for(int k=i+1;k<p;k++){
			if(n[1][i]<n[1][k]){
				temp=n[1][i];
				n[1][i]=n[1][k];
				n[1][k]=temp;
				temp=n[0][i];
				n[0][i]=n[0][k];
				n[0][k]=temp;
			}
		}
	}
	dd=n[1][0];
	for(int i=0;i<p;i++){
		if(n[1][i]==dd)n[1][i]=bb;
		else if(n[1][i]<dd){
			dd=n[1][i];
			bb++;
			n[1][i]=bb;
		}
	}
	for(int i=0;i<p;i++){
		for(int k=i+1;k<p;k++){
			if(n[0][i]>n[0][k]){
				temp=n[1][i];
				n[1][i]=n[1][k];
				n[1][k]=temp;
				temp=n[0][i];
				n[0][i]=n[0][k];
				n[0][k]=temp;
			}
		}
	}
	while(scanf("%d",&temp)!=EOF){
		cout<<n[1][temp-1]<<endl;
	}
	return 0;
}