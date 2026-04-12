#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
	int n,a[200000],i,b[200000];
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b,b+n);
	for(i=0;i<n;i++){
		if(abs(a[i]-b[n/2])>=abs(a[i]-b[n/2-1]))cout<<b[n/2]<<endl;
		if(abs(a[i]-b[n/2])<abs(a[i]-b[n/2-1]))cout<<b[n/2-1]<<endl;
	}
}