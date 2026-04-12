#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MaxN = 53;
int n;
LL a[MaxN];

int main() {
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n;
	for (int i=1;i<=n;++i) cin >> a[i];
	sort(a+1,a+n+1);
	LL ans=0;
	while (a[n]>=n) {
		LL x=a[n]/n;
		ans+=x;
		a[n]%=n;
		for (int i=1;i<=n-1;++i) a[i]+=x;
		sort(a+1,a+n+1);
	} 
	cout << ans << endl;
	return 0;
}