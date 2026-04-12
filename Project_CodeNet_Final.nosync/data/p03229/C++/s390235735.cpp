#include<iostream>
#include<math.h>
#include <algorithm>
using namespace std;

int main(){
	int a[100000];
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	long long int ans=0;
	if(n%2==0){
		for(int i=n-1;i>n/2;i--){ans+=(2*a[i]);}
		ans+=a[n/2];
		ans-=a[n/2-1];
		for(int i=0;i<n/2-1;i++){ans-=(2*a[i]);}
	}
	else{
		for(int i=n-1;i>(n-1)/2+1;i--){ans+=(2*a[i]);}
		for(int i=0;i<(n-1)/2-1;i++){ans-=(2*a[i]);}
		int p=a[(n+1)/2]+a[(n-1)/2]-2*a[(n-1)/2-1];
		int pp=2*a[(n+1)/2]-a[(n-1)/2]-a[(n-1)/2-1];
		ans+=max(p,pp);
	}
	cout<<ans<<endl;
}