#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<cstring>
using namespace std;

int main(){
	int n;
	while(1){
		int i,sum=0,a=0,max=0,min=0,s=0;
		cin>>n;
		if(n==0)break;
		cin>>sum;
		max=sum;min=sum;
		for(i=1;i<n;i++){
			cin>>a;
			sum+=a;
			if(min>a)min=a;
			if(max<a)max=a;
		}
		s=(sum-max-min)/(n-2);
		cout<<s<<endl;
	}
    return 0;
}