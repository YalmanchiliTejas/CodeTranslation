#include<stdio.h>
#include<iostream>
using namespace std;
int d[1000000]={0};
int s[1000000]={0};
int main(void){
	int n=0;
	int a=0;
	int max=0;
	int i=0;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>d[i];
		a+=d[i];
	}
	if(d[0]<10){
		cout<<"no"<<endl;
		return 0; 
	}
	for(i=1,max=d[0]/10;(i<=max)&&(i<n);++i){
		if(max<d[i]/10+i){//(d[i]/10)+i
			max=i+d[i]/10;
		}
	}
	if(i!=n){
		cout<<"no"<<endl;
		return 0;
	}
	if(d[n-1]<10){
		cout<<"no"<<endl;
		return 0; 
	}
	for(i=n-2,max=d[n-1]/10;((n-1)-i<=max)&&(i>=0);i--){//when can go right end
		if(max<d[i]/10+(n-1)-i){//(d[i]/10)+i//update max value
			max=d[i]/10+(n-1)-i;
		}
	}
	if(i!=-1){
		cout<<"no"<<endl;
		return 0;
	}
	else if(i==-1){
		cout<<"yes"<<endl;
		return 0;
	}
	return 0;
}
