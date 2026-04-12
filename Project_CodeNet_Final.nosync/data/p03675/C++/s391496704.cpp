#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,a[200000];
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=n-1;i>=0;i-=2)
		cout<<a[i]<<' ';
	for(int i=n%2;i<n;i+=2)
		cout<<a[i]<<(i+2==n?'\n':' ');
}
