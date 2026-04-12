#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n;
	int t[100];
	while(1){
		cin>>n;
		if(0==n){
			break;
		}
		for(int i=0;i<n;i++){
			cin>>t[i];
		}
		sort(t,t+n);
		int sum=0;
		for(int i=1;i<n-1;i++){
			sum+=t[i];
		}
		cout<<sum/(n-2)<<endl; 
		
	}
} 
