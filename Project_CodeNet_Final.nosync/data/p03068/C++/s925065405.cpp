#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
	char a[100];
	int n,k;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cin>>k;
	for(int i=0;i<n;i++){
		if(a[i]!=a[k-1]){
			a[i]='*';
		}
	}
	for(int i=0;i<n;i++){
		cout<<a[i];
	}
	return 0;
}