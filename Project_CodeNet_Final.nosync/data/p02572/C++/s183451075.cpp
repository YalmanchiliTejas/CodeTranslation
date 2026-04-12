#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define sc(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d%d",&a,&b)
#define ss(a) scanf("%s",a)
#define mem(a,b) memset(a,b,sizeof(a))
#define PII pair<int,int>
const double pi = acos(-1.0);
using namespace std;
const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;
ll a[maxn], sum[maxn], ans;
int main(){
	int n;
	scanf("%d",&n);
	for(int i = 1; i <= n; i ++){
		scanf("%lld",&a[i]);
		sum[i] = sum[i - 1] + a[i];
		sum[i] = sum[i] % mod;
	}
	for(int i = n; i > 1; i --){
		ans = ans + a[i] * sum[i - 1] % mod;
		ans = ans % mod;
	}
	printf("%lld\n",ans);
	return 0;
}