#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[114514];
ll num[2];
int main(){
	ll n;
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	ll ans=0;
	if(n%2){
		for(int i=0;i<(n-1)/2;i++){
			num[1]+=2*a[n-1-i];
			num[2]-=2*a[i];
		}
		num[1]-=a[n-1-(n-1)/2]+a[n-2-(n-1)/2];
		num[2]+=a[(n-1)/2]+a[(n-1)/2+1];
		for(int i=(n-1)/2+2;i<n;i++){
			num[1]-=2*a[n-1-i];
			num[2]+=2*a[i];
		}
		ans=max(num[1],num[2]);
	}else{
		for(int i=0;i<n/2-1;i++)ans-=2*a[i];
		ans+=a[n/2]-a[n/2-1];
		for(int i=n/2+1;i<n;i++)ans+=2*a[i];
	}
	cout<<ans<<endl;
	return 0;
}
