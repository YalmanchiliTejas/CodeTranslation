#include<iostream>
using namespace std;
int f(int n, int a[], int k){
	int right=n;
	int left=0;
	//if(k>a[n-1])
		//return n;
	while(left<right){
		int m=(left+right)/2;
		if(a[m]>=k){
			if(a[m-1]<k || m==0)
				return m;
			else
				right=m;
		}
		else{
			if(a[m+1]>k)
				return m+1;
			else
				left=m+1;
		}
	}
	return n;
}
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	int q;
	cin>>q;
	while(q--){
		int k;
		cin>>k;
		cout<<f(n,a,k)<<endl;
	}
	return 0;
}
