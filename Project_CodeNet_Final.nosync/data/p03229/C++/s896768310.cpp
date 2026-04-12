#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	long long n,s=0,t=0;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
	    cin>>a[i];
	}
	sort(a,a+n);
	s+=a[n/2]-a[0];
	for(int j=0;j<n-2;j++){
	    if(j%2==0){
	        s=s-a[j/2]+a[n-j/2-1];
	    }
	    else{
	        s=s+a[n-j/2-1]-a[j/2+1];
	    }
	    //cout<<s<<endl;
	}
	sort(a,a+n,greater<>());
	t+=a[0]-a[n/2];
	for(int j=0;j<n-2;j++){
	    if(j%2==0){
	        t=t+a[j/2]-a[n-j/2-1];
	    }
	    else{
	        t=t-a[n-j/2-1]+a[j/2+1];
	    }
	    //cout<<s<<endl;
	}
	cout<<max(t,s);
	return 0;
}
