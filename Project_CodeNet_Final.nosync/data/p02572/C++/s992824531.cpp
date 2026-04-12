#include<bits/stdc++.h>
typedef double db;
typedef long long ll;
using namespace std;

const ll mo = 1e9+7;
const int N = 2e5+7;

int n;
ll ans, a[N], b[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%lld",&a[i]);
	for(int i = n; i >= 1; i--)
		b[i] = (a[i] + b[i+1])%mo;
	for(int i = 1; i <= n; i++){
		ans  = (ans + a[i]*b[i+1]%mo)%mo;
	}
	printf("%lld\n", ans);
	return 0;
}
