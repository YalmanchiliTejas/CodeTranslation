
#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned ll
#define db double
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define PII pair<int, int>

const int N=60;
int n;
ll a[N],x[N],y[N];

bool ok() {
	for (int i=0;i<n;i++) {
		if (x[i]!=0) return false;
	}
	return true;
}

int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		scanf("%lld",a+i);
		y[i]=a[i]%n;
		x[i]=(a[i]-y[i])/n;
	}
	ll ans=0;
	while (!ok()) {
		ll sum=0;
		for (int i=0;i<n;i++) sum+=x[i];
		ans+=sum;
		for (int i=0;i<n;i++) {
			a[i]=y[i]+sum-x[i];
			y[i]=a[i]%n;
			x[i]=(a[i]-y[i])/n;
		}
	}
	printf("%lld\n",ans);
}
