#include <bits/stdc++.h>
using namespace std;
int n,a[300001],sum,f;
int main(){
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++){
		sum=max(sum-10,a[i]);
		if(sum<10)f++;
	}
	sum=0;
	for(int i=n-1;i>=0;i--){
		sum=max(sum-10,a[i]);
		if(sum<10)f++;
	}
	cout<<(f?"no":"yes")<<endl;
}