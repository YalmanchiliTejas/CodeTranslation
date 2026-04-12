#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 60;
ll a[N];
ll n;
ll cnt;

int main() {
	//freopen("in.txt","r",stdin);
	cnt = 0;
	scanf("%lld",&n);
	for(int i=0;i<n;i++)scanf("%lld",&a[i]);
	sort(a,a+n);
	while(a[n-1] >= n) {
		ll tmp = a[n-1]/ n;
		cnt += tmp;
		a[n - 1] -= tmp * n;
		for(int i=0;i<n-1;i++)a[i] += tmp;
		sort(a,a+n);
	}	
	cout<<cnt<<endl;
	return 0;
}