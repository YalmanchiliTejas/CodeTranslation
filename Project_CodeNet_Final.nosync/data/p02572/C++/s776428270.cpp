#include<iostream>
#define MAXNUM 1000000007
using namespace std;
int main(){
	int n;
	long long int a[200005];
	cin>>n;
	long long int sum=0;
	
	for(int i=0;i<n;i++){
		cin>>a[i];	
	}
	long long int front=0;
	long long int last=0;
	for(int i=1;i<n;i++){
		front=a[i];
		last+=a[i-1];
		last=last%1000000007;
		sum+=(front*last);
		sum=sum%1000000007;
	}
//	long long int cnt=1;
	cout<<sum;

}