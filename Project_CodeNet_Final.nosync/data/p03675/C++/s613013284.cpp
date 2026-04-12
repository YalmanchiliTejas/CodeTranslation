#include <iostream>
using namespace std;
void reverse(int b[],int n){
	int temp[n];
	
	for (int i=0;i<n;i++){
		
	}
}
int main() {
	int n,input,count=0;
	cin>>n;
	int b[n],c[n];
	for (int i=0;i<n;i++){
		cin>>b[i];
	}
	for (int i=n-1;i>=(!(n%2));i-=2){
		c[count]=b[i];
		count++;
	}
	for (int i=((n%2));i<n-1;i+=2){
		c[count]=b[i];
		count++;
	}
	for (int i=0;i<n;i++){
		b[i]=c[i];
	}
	for (int i=0;i<n;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}