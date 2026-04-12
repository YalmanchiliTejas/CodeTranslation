#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,ans[60],k,b[60],s;
bool t;
int main() {
	scanf("%lld",&n);
	for (int i=1;i<=n;i++)
		scanf("%lld",&ans[i]);
	k=0;
	while (1) {
		s=0;
		for (int i=1;i<=n;i++) {
			b[i]=ans[i]/n;
			s+=b[i];
		}
		k+=s;
		t=false;
		for (int i=1;i<=n;i++) {
			ans[i]-=b[i]*n;
			ans[i]+=s-b[i];
			if (ans[i]>=n)
				t=true;
		}
		if (!t)
			break;
	}
	printf("%lld\n",k);
	return 0;
}