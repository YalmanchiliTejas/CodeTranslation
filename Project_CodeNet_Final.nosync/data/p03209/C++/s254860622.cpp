#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

ll n,x;
ll c[51];
map<pair<ll, ll>, long long> m;
ll ans(ll n, ll x)
{
	//debug(c[n]);
	//debug(n, x);
	if(n == 0 && x) return 1;
	if(n == 1 && x == 1) return 0;
	else if(n == 1 && x == 2) return 1;
	else if(n == 1 && x == 3) return 2;
	else if(n == 1 && x) return 3;
	if(x <= 0) return 0;
	if(x > c[n]) x = c[n];
	if(m[{n, x}]) return m[{n, x}];
	ll temp = c[n-1];
	//debug(temp);
	if(c[n-1] +1 >= x)
	{
		long long flag = ans(n-1, x-1);
		m[{n-1, x-1}] = flag;
		return flag;
	}
	else if(c[n-1] + 1 + 1 >= x)
	{
		ll flag = ans(n-1, x-1);
		m[{n-1, x-1}] = flag;
		return 1 + flag;
	}
	else
	{
		ll flag = ans(n-1, c[n-1]);
		ll flag1 = ans(n-1, x - c[n-1] - 1 - 1);
		m[{n-1, c[n-1]}] = flag;
		m[{n-1, x - c[n-1] - 1 -1 }] = flag1;
		return 1 + flag + flag1;
	}

}

int main()
{
	cin >> n >> x;
	c[0] = 1;
	for(ll i=1;i<=n;i++)
	{
		c[i] = 1 + c[i-1] + 1 + c[i-1] + 1;
	}
	cout << ans(n, x) << "\n";
	return 0;
}