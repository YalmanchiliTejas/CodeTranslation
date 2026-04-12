#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main(){
	int n;
	cin >> n;
	ll a[n];
	for(int i=0; i<n; i++){
		cin >> a[i];
		a[i]*=-1;
	}
	ll d[n];
	for(int i=0; i<n; i++) d[i]=1;
	for(int i=0; i<n; i++){
		*upper_bound(d, d+n, a[i])=a[i];
	}
	cout << lower_bound(d, d+n, 1)-d << endl;

	return 0;
}