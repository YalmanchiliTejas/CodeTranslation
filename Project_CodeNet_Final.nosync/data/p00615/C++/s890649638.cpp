#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
	int N,M;

	while(1){
		cin>>N>>M;if(N==0&&M==0)break;
		int n[20003]={};

		for(int i=0;i<N+M;i++)
			cin>>n[i];


		sort(n,n+N+M);
		
		int max=n[0];
		for(int i=0;i<N+M;i++){//cout<<n[i]<<endl;
			if(n[i+1]-n[i]>max)max=n[i+1]-n[i];}
		cout<<max<<endl;
	}
	return 0;
}
	
		