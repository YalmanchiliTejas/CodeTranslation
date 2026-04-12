#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],num,ans;
long long x(long long b,long long c){
	if (b>=c)
		return b-c;
	else
		return (1000000007+(b-c));
}
int main(){
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	for (int i=0;i<n;i++) num+=a[i],num=num%(1000000007);
//	for (int i=0;i<n;i++) ans=(ans+x(num,a[i])*a[i])%(1000000007);
//	cout<<(ans%1000000007)/2<<endl;;
	for (int i=0;i<n;i++){
		num=x(num,a[i]);
		ans=(ans+num*a[i])%(1000000007);
	}
	cout<<(ans%1000000007)<<endl;
	return 0;
}