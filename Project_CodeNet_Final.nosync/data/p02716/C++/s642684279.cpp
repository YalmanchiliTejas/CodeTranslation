#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
const ll N = 2e5+5;

ll a[N], d[N], s[N], n, i;

main(){
	cin >> n;
	for(; i < n; ++i)
	{
		cin >> a[i];
		s[i] = (i > 1 ? s[i - 2] : 0) + a[i];
	}
	for (i = 1; i < n; ++i)
	{
		if (i & 1)
			d[i] = max(s[i - 1], d[i - 2] + a[i]);
		else
			d[i] = max(d[i - 1], d[i - 2] + a[i]);
	}
	cout << d[n - 1];
}