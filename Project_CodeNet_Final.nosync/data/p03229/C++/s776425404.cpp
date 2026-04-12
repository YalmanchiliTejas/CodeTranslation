#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	long long a[100010];
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
	} 
	sort(a,a+n);
	long long sum=0;
	if(n%2==0){
		for(int i=0;i<n/2-1;i++){
			sum+=a[n-i-1];
			sum-=a[i];
		}
		sum=sum*2;
		sum+=a[n/2];
		sum-=a[n/2-1];
	}
	else{
		for(int i=0;i<n/2-1;i++){
			sum+=a[n-i-1];
			sum-=a[i];
		}
		sum=sum*2;
		int a1=a[n/2+1]*2-a[n/2]-a[n/2-1];
		int b1=a[n/2+1]+a[n/2]-2*a[n/2-1];
		sum+=max(a1,b1);
	}
	cout<<sum;
	return 0;
}