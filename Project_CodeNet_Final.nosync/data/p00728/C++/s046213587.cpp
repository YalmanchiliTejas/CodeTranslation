#include <iostream>
#include <math.h>
using namespace std;

int main(){
	
	while(1){
		
		int n,s[100],m=1000,M=0,sum=0;
		cin>>n;
		if(n==0)break;
		
		for(int i=0;i<n;i++)cin>>s[i];
		
		for(int i=0;i<n;i++){
			sum+=s[i];
			if(s[i]<m)m=s[i];
			if(s[i]>M)M=s[i];
		}
		
		cout<<(sum-m-M)/(n-2)<<endl;
	}
	return 0;
}