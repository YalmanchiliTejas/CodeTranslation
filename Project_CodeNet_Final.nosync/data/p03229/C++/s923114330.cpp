#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]);

	vector<int> coef(n-1);
	rep(i,n/2) coef[i]=coef[n-2-i]=2*(i+1);
	coef[n/2-1]--;

	sort(a.begin(),a.end());
	lint res1=0;
	rep(i,n-1) res1+=coef[i]*abs(a[i+1]-a[i]);

	reverse(a.begin(),a.end());
	lint res2=0;
	rep(i,n-1) res2+=coef[i]*abs(a[i+1]-a[i]);

	printf("%lld\n",max(res1,res2));

	return 0;
}
