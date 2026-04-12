#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back

using namespace std;
typedef long long ll;

const int MAXN = 1000*1000 + 7;
const int SS = 1<<20;
const int MOD = 998244353;

bool bylo[MAXN];
int ind[MAXN];
long long poprz[MAXN];
long long ile[MAXN];
long long n, x, m;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);

	int T;
	//cin >> T;
	T = 1;
	while(T--)
	{
		cin >> n >> x >> m;
		long long a = x;

		long long sum = 0;
		long long i = 0;
		long long last = 100000 + 7;
		while( bylo[a] == false )
		{
			bylo[a] = true;
			poprz[a] = last;
			sum += a;
			ile[a] = sum;
			ind[a] = i;
			last = a;
			a = (a*a) % m;
			i++;
			if( i >= n )
				break;
		}
		long long d = i - ind[a];
		sum += (sum - ile[poprz[a]]) * ((n-i)/d);
		n = (n-i)%d;
		for(long long j=1; j<=n; j++)
		{
			sum += a;
			a = (a*a) % m;
		}
		cout << sum << '\n';
	}
	return 0;
}
