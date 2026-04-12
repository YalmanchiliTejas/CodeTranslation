#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
ll n, x, s, a[55]={1}, b[55]={1};

void f(ll p, ll q) {
	if(p==0) {s++; return;}
	ll md = (a[p]+1)/2;
	if(q==1) return;
	else if(q < md) f(p-1, q-1);
	else if(q==md) {s += b[p-1] + 1; return;}
	else {
		s += b[p-1] + 1;
		f(p-1, q-md);
	}
}

int main() {
	int i;
	cin>>n>>x;
	for(i=1; i<=n; i++) {
		a[i] = a[i-1]*2 + 3;
		b[i] = b[i-1]*2 + 1;
	}
	f(n, x);
	cout<<s;
	return 0;
}
