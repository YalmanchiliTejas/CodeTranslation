#include<iostream>
#include<vector>
#include<map>
#include<set>
using namespace std;

int main(){
	int n;
	cin>>n;
	
	vector<int> a(n);
	
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	if(n%2==0){
		for(int i=0;i<n;i+=2){
			cout<<a[n-i-1]<<" ";
		}
		
		for(int i=0;i<n;i+=2){
			cout<<a[i]<<" ";
		}
	}else{
		for(int i=0;i<n;i+=2){
			cout<<a[n-i-1]<<" ";
		}
		
		for(int i=1;i<n;i+=2){
			cout<<a[i]<<" ";
		}
	}
	
	cout<<endl;
	
	
	
	return 0;
}