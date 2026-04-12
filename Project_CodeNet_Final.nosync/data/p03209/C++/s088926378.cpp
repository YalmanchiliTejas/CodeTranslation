#include <cstdio>
#include <iostream>
using namespace std;
long long num[55];
long long work(int n,long long x){
	if(x<=0){
		return 0;
	}
	if(n==0){
		return 1;
	}
	if(x==num[n]){
		return 1+(work(n-1,num[n-1])<<1);
	}
	if(x>=num[n-1]+2){
		return 1+work(n-1,num[n-1])+work(n-1,x-num[n-1]-2);
	}
	return work(n-1,x-1);
}
int main(){
	num[0]=1;
	for(int i=1;i<=50;i++){
		num[i]=(num[i-1]<<1)+3;
	}
	int n;
	long long x;
	scanf("%d",&n);
	cin>>x;
	cout<<work(n,x)<<endl;
	return 0;
}
