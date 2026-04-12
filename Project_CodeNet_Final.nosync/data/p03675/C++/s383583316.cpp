#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define repp(i, m, n) for(int i = m; i < n; i++)
#define reps(i, n) for(int i = 1; i <= n; i++)
const int    INF = 100000000;
const double EPS = 1e-10;
const int    MOD = 1000000007;
using namespace std;
typedef long long ll;
typedef pair<int, int> pai;
typedef pair<ll,ll> pal;



int main()
{
	int n;
	int a[200010];
	cin >> n;
	rep(i, n) cin >> a[i];
	if(n%2==0)
	{
		rep(i, n/2)
		{
			cout << a[n-1-2*i] << " ";
		}
		rep(i, n/2)
		{
			cout << a[2*i];
			if(i!=n/2-1) cout << " ";
			else cout << endl;
		}
	}
	else if(n>1)
	{
		rep(i, 1+n/2)
		{
			cout << a[n-1-2*i] << " ";
		}
		rep(i, n/2)
		{
			cout << a[2*i+1];
			if(i!=n/2-1) cout << " ";
			else cout << endl;
		}
	}
	else cout << a[0] << endl;
	return 0;
}