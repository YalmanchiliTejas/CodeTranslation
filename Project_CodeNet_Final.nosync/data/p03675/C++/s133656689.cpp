#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#define mod 1000000007
using namespace std;
string a[200009];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n%2==0){
		for(int i=n;i>=2;i-=2){
			cout<<a[i]<<" ";
		}
		for(int i=1;i<n;i=i+2){
			cout<<a[i]<<" ";
		}
		cout<<endl;
	}
	if(n%2==1){
		for(int i=n;i>=1;i-=2){
			cout<<a[i]<<" ";
		}
		for(int i=2;i<n;i=i+2){
			cout<<a[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}