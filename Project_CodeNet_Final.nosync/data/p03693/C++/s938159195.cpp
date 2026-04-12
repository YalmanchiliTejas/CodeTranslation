#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair
#define pii pair<int, int> 
#define pll pair<long long int, long long int>
#define sci(x) scanf("%d", &x)
#define scl(x) scanf("%lld", &x)
#define fi first
#define sc second
#define deb 0

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int x, y;
	cin >> x; cin >> y; x = x * 10 + y;
	cin >> y; x = x * 10 + y;
	if (x%4) cout << "NO" << endl;
	else cout << "YES" << endl;

	return 0;
}