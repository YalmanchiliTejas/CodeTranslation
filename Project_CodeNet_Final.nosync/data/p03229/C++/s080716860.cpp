#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main(){
	int n;
	cin >> n;
	ll a[n];
	for(int i=0; i<n; i++) cin >> a[i];
	sort(a, a+n);

	ll ans=0;
	if(n%2==0){
		int k=n/2;
		for(int i=k; i<n; i++) ans+=2*a[i];
		for(int i=0; i<k; i++) ans-=2*a[i];
		ans+=a[k-1]-a[k];
	}else{
		int k=(n-1)/2;
		ll t1=0, t2=0;

		for(int i=k+1; i<n; i++) t1+=2*a[i];
		for(int i=0; i<k+1; i++) t1-=2*a[i];
		t1+=a[k-1]+a[k];

		for(int i=k; i<n; i++) t2+=2*a[i];
		for(int i=0; i<k; i++) t2-=2*a[i];
		t2-=a[k]+=a[k+1];

		ans=max(t1, t2);
	}
	cout << ans << endl;
	return 0;
}