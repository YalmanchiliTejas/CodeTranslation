#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define gc() fgetc(stdin)
ll read() {
	ll a = 0; int b = 1, c;
	while (((c=gc()) > '9' || c <'0') && c != '-');
	if (c=='-') b=-1,c=gc();
	while (c >= '0' && c <= '9') a=a*10+c-'0',c=gc();
	return a*b;
}
#define gs(s) scanf("%s",s)
#define gi(i) i=read()
#define gl(i) i=read()
#define pc(c) putchar(c)
#define ps(s) printf("%s",s)
#define pi(i) printf("%d",i)
#define pl(i) printf("%lld",i)

int n, X[200005], V[200005];

int main() {
	gi(n);
	for (int i = 0; i < n; i++) gi(X[i]);
	for (int i = 0; i < n; i++) V[i] = X[i];
	sort(V, V+n);
	for (int i = 0; i < n; i++) {
		if (X[i] < V[n/2]) {
			pi(V[n/2]);
		} else {
			pi(V[n/2-1]);
		}
		pc('\n');
	}
	return 0;
}
