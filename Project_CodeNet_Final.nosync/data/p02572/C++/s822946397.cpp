#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define MOD 1000000007
#define endl "\n"
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(var) (var).begin(), (var).end()
#define sz(x) (int)x.size()
#define MAXX 9000000000000000000
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int> >
#define vpi vector<pair<int,int> > 
#define vvpi vector<vector<pair<int,int> > >

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int n,i,j,x,y,a[200005],ans=0,b[200005];
	cin >> n;
	b[0]=0;
	for(i=0;i<n;i++)
	{
		cin >> a[i];
		if(i)
		{
			b[i] = b[i-1] + a[i-1];
			b[i] %= MOD;
		}
	}

	for(i=0;i<n;i++)
	{
		ans += (a[i] * b[i]);
		ans %= MOD;
	}

	cout << ans;
	
	return 0;
}