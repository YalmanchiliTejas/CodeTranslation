#include<iostream>
using namespace std;
int main(){
	int n,x,max,min,pre;
	while(cin>>n,n){
		cin>>x;
		pre=x;
		max=x;
		min=x;
		for(int i=0;i<n-1;i++){
			cin>>x;
			pre+=x;
			if(max<x)
				max=x;
			if(min>x)
				min=x;
		}
		cout<<(pre-max-min)/(n-2)<<endl;
		
		
		
		
	}
	return 0;
}