#include<cstdio>
#include<iostream>
using namespace std;
int main(){
	int n,m,x,sum=0;
	cin>>n>>m>>x;
	n-=x;
	while(n-x-m>=0){
		n-=x;
		n-=m;
		sum++;
	}
	cout<<sum;
	return 0;
} 