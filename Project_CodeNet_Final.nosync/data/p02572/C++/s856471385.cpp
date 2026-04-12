#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n;
	long long m,sn,a,ans;

	cin >> n ;
	cin >> a ;
	m=1e9+7;
	sn=a;
	ans=0;
	rep(i, n-1){
		cin >> a ;
		ans+=sn*a;
		ans%=m;
		sn+=a;
		sn%=m;
	}
	cout << ans << endl;

	return 0;
}