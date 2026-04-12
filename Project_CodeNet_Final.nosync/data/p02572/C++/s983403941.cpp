#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef long long ll;

#define f first
#define s second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rsz resize

const int md = 1e9+7;
const ll inf = 1e18;
const int maxn = 2e5+5;

template<class T> void ckmin(T &a, T b) { a = min(a, b); }
template<class T> void ckmax(T &a, T b) { a = max(a, b); }

void add(int &a, int b)
{
	a += b;
	if(a >= md) a -= md;
}

void sub(int &a, int b)
{
	a -= b;
	if(a< 0) a += md;
}

int mul(int a, int b)
{
	return (1LL*a*b)%md;
}

int expo(int a, int b)
{
	if(b == 0) return 1;
	int x = expo(a, b/2);
	int res = mul(x, x);
	if(b%2) res = mul(res, a);
	return res;
}

int inv(int x)
{
	return expo(x, md-2);
}

int main()
{
	int n; scanf("%d", &n);
	int sum = 0;
	int ssq = 0;
	for(int i = 0; i< n; i++)
	{
		int x; scanf("%d", &x);
		add(sum, x);
		add(ssq, mul(x, x));
	}

	int res = mul(sum, sum);

	sub(res, ssq);

	int ret = mul(res, inv(2));

	printf("%d\n", ret);
}