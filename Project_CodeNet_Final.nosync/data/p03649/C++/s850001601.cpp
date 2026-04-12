#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAXN 200010
#define X first
#define Y second

priority_queue<ll> Q;

int main()
{
	//freopen("in.in", "r", stdin);
	//freopen("out.out", "w", stdout);
	
	int N; ll del = 0, res = 0;
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)
	{
		ll x;
		scanf("%lld", &x);
		Q.push(x);
	}
	while (true)
	{
		ll x = Q.top() + del;
		Q.pop();
		if (x  < N) break;
		
		ll k = x / N;
		del += k, res += k;
		Q.push(x - k * N - del);
	}
	printf("%lld\n", res);
	
	return 0;
}