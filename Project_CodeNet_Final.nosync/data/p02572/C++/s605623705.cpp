#include <bits/stdc++.h>

#define ll long long
#define modu 1000000007

using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int n;
	cin >> n;
	ll a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	ll ps[n];
	ll last=0;
	int o = 0;
	for(int i = n-1; i >= 0; i--)
	{
		ll now = last + a[i];
		ps[o] = now;
		last = now;
		o++;
	}
	reverse(ps, ps+n);


	ll sum=0;
	for(int i = 0; i < n; i++){
		ll psum=(ps[i]-a[i])%modu;
		ll psum2 = (psum * a[i])%modu;
		sum = (sum + psum2)%modu;
	}
	cout << sum << endl;
}
