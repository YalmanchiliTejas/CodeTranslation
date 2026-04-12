#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	int a[300000];
	int b[300000];
	cin>>n;
	int f=0;
	for(int i=0;i<n;i++){cin>>a[i];}
	if(n%2==0){
		for(int i=n-1;i>0;i-=2){if(f)cout<<" ";f=1;cout<<a[i];}
		for(int i=0;i<n-1;i+=2){if(f)cout<<" ";f=1;cout<<a[i];}
	}
	else{
		for(int i=n-1;i>=0;i-=2){if(f)cout<<" ";f=1;cout<<a[i];}
		for(int i=1;i<n-1;i+=2){if(f)cout<<" ";f=1;cout<<a[i];}
	}
	cout<<endl;
	return(0);
}