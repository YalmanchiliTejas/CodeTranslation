#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define ll long long
#define pq priority_queue
#define mii map<int,int>

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef set<int> si;
typedef vector<vi> vii;
typedef vector<ii> vpi;
typedef vector<ll> vll;
int oo = (1e9) + 7;

int n;
vi v(3005, 0);
ll tb[3005][3005][2];
int calc[3005][3005][2];

ll dp(int i, int j, bool player) {
	if(i == j) return player == 1 ? -v[i] : v[i];
	if(calc[i][j][player]) return tb[i][j][player];

	ll ans = 0;
	if(player == 0) ans = max(dp(i+1, j, 1) + v[i], dp(i, j-1, 1) + v[j]);
	else ans = min(dp(i+1, j, 0) - v[i], dp(i, j-1, 0) - v[j]);

	tb[i][j][player] = ans;
	calc[i][j][player] = 1;
	return ans;
}

int main()
{
    cin >> n;

	
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &v[i]);
	}
	memset(tb, -1, sizeof tb);
	printf("%lld\n", dp(0, n-1, 0));

	return 0;

}