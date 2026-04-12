#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
unsigned long long a[1000005],cnt,sum;
int n;
int main() {
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		sum=sum+a[i];
	}
	for (int i=1;i<=n;i++) {
		sum=sum-a[i];
		cnt=(cnt+(sum%mod*a[i])%mod)%mod;
	}
	cout<<cnt<<endl;
	return 0;
}