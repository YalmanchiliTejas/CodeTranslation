#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define MAX 5000000000000000000LL
#define MIN -5000000000000000000LL

ll n, x, m, xx;
map<ll, ll> chk;
ll cou;
ll hap;
ll ans;

int main(void)
{
	scanf("%lld %lld %lld", &n, &x, &m);
	
	xx = x;
	
	chk[x] = 1;
	
	while(1)
	{
		x = (x * x) % m;
		
		if(chk[x])
			break;
		
		chk[x] = 1;
	}
	
	while(n > 0 && xx != x)
	{
		ans += xx;
		xx = (xx * xx) % m;
		n--;
	}
	
	xx = x;
	
	hap += x;
	cou++;
	x = (x * x) % m;
	
	while(x != xx)
	{
		hap += x;
		cou++;
		x = (x * x) % m;
	}
	
	ans += (n / cou) * hap;
	
	n %= cou;
	
	for(ll i = 0 ; i < n ; i++)
	{
		ans += x;
		x = (x * x) % m;
	}
	
	printf("%lld", ans);
	return 0;
}