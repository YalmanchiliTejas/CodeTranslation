#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
	long long a[100000+5];
	long long n,z,y,sz,sy;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	sz=1;sy=n-1;
	z = a[0];
	y = a[0];
	long long sum = 0;
	while(sz<=sy){
		long long z1,z2,z3,z4;
		z1 = fabs(z-a[sz]);
		z2 = fabs(z-a[sy]);
		z3 = fabs(y-a[sz]);
		z4 = fabs(y-a[sy]);
		long long m;
		m=max(max(z1,z2),max(z3,z4));
		sum+=m;
		if(m == z1)
			z = a[sz++];
		else if(m == z2)
			z = a[sy--];
		else if(m == z3)
			y = a[sz++];
		else if(m == z4)
			y = a[sy--];
	}
	cout<<sum<<endl;
	return 0;
}