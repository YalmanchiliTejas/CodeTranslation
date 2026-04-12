#include<bits/stdc++.h>

#define sc second
#define fr first

#define ll long long
#define pi pair<int,int>
#define ppi pair<pi,pi>
#define mp make_pair
using namespace std;


int main()
{

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);


	int n; cin >> n;
	int mx = 0;
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int x; cin >> x;
		if (x >= mx)
			ans++;
		mx = max(mx, x);
	}
	cout << ans << '\n';




	return 0;
}
