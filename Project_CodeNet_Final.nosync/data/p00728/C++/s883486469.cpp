#include<iostream>
using namespace std;

int main(){
	int n;
	int j[110];
	int max,min;
	for(;cin>>n,n!=0;){
		for(int i=0;i<n;i++){
			cin>>j[i];
		}
		max=0;
		min=2000;
		int sum=0;
		for(int i=0;i<n;i++){
			if(max<j[i])max=j[i];
			if(min>j[i])min=j[i];
			sum+=j[i];
		}
		sum-=max+min;
		cout<<sum/(n-2)<<endl;
	}
	return 0;
}