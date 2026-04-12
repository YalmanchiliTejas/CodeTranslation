#include <bits/stdc++.h>
	
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<db, db> pdd;
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define loop(i, a, b) for(int i = a; i < b; i++)
#define pool(i, a, b) for(int i = a; i > b; i--)
#define pb push_back

const int maxn = 1e5+5;
const int Mod=1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const double e=exp(1);
const db PI = acos(-1);
const db ERR = 1e-10;

const int nax =3005;
ll dp[nax][nax];

int main()
{
	int n;
	fastIO
	scanf("%d", &n);
	vector <int> a(n);
	for(int& x : a)
		scanf("%d", &x);

	for(int L = n - 1; L >= 0; L--)
	{
		for(int R = L; R < n; R++)
		{
			if(L == R)
			{
				dp[L][R] = a[R];
			}
			else
			{
				dp[L][R] = max(a[L] - dp[L + 1][R], a[R] - dp[L][R - 1]);
			}
		}
	}
	cout << dp[0][n - 1];

	return 0;
}