#include<bits/stdc++.h>
using namespace std;
#define pb  					push_back
#define mp 						make_pair
#define all(v) 					((v).begin()) ,((v).end())
#define let(o,v)				memset(o,v,sizeof (o))
typedef long long 				ll;
typedef vector<int>				vi;
typedef vector<vi>				vvi;
typedef vector<string>			vs;

const int MOD = 998244353;
const int oo = (int)1e9;
const ll OO = (ll)1e18;
const double PI = acos(-1.0);
const int N = (int)1e5 + 9;

bool isprime(ll n) {
	if (n <= 1)
		return 0;
	for (ll i = 2; i*i <= n; i++)
		if (n%i == 0)
			return false;
	return 1;
}
ll intlog(ll base, ll x) {
	return (log(x) / log(base));
}
bool prime[N];
void primee()
{

	for (int p = 2; p*p <= N; p++)
	{

		if (prime[p] == true)
		{
			for (int i = p * 2; i < N; i += p)
				prime[i] = false;
		}
	}

}
string decToBinary(ll n)
{
	string z = "";
	int i = 0;
	while (n > 0) {

		z += (n % 2) + 48;
		n = n / 2;
		i++;
	}
	reverse(all(z));
	return z;
}
ll gcd(ll a, ll b) {
	return b == 0 ? a : gcd(b, a%b);
}
ll power(ll x, int y)
{
	ll temp;
	if (y == 0)
		return 1;
	temp = power(x, y / 2);
	if (y % 2 == 0)
		return temp * temp;
	else
		return x * temp*temp;
}
int n;
deque<ll> q;
ll dp[3000][3000];
ll calc(int i, int j,int k) {
	if (i > j) {
		return 0;
	}
	ll &ret = dp[i][j];
	if (ret != -1) return ret;
	if (k % 2 == 0) {
		ret = max(q[i]+calc(i + 1, j, k + 1),q[j]+ calc(i, j - 1, k + 1));
	}
	else {
		ret = OO;
		ret = min(-q[i]+calc(i + 1, j, k + 1),-q[j]+ calc(i, j - 1, k + 1));
	}
	return ret;
}
int main()
{
	let(dp, -1);
	scanf("%d", &n);
	q.resize(n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &q[i]);
	}
	printf("%lld\n", calc(0, n - 1, 0));
	return 0;
}