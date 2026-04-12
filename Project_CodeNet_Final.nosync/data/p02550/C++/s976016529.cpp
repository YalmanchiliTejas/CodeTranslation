/*
 ▓█████▄  ▄████▄  ▓██   ██▓ ██▓███   ██░ ██ ▓█████  ██▀███
▒██▀ ██▌▒██▀ ▀█   ▒██  ██▒▓██░  ██▒▓██░ ██▒▓█   ▀ ▓██ ▒ ██▒
 ░██   █▌▒▓█    ▄   ▒██ ██░▓██░ ██▓▒▒██▀▀██░▒███   ▓██ ░▄█ ▒
 ░▓█▄   ▌▒▓▓▄ ▄██▒  ░ ▐██▓░▒██▄█▓▒ ▒░▓█ ░██ ▒▓█  ▄ ▒██▀▀█▄
 ░▒████▓ ▒ ▓███▀ ░  ░ ██▒▓░▒██▒ ░  ░░▓█▒░██▓░▒████▒░██▓ ▒██▒
  ▒▒▓  ▒ ░ ░▒ ▒  ░   ██▒▒▒ ▒▓▒░ ░  ░ ▒ ░░▒░▒░░ ▒░ ░░ ▒▓ ░▒▓░
  ░ ▒  ▒   ░  ▒    ▓██ ░▒░ ░▒ ░      ▒ ░▒░ ░ ░ ░  ░  ░▒ ░ ▒░
  ░ ░  ░ ░         ▒ ▒ ░░  ░░        ░  ░░ ░   ░     ░░   ░
    ░    ░ ░       ░ ░               ░  ░  ░   ░  ░   ░
  ░      ░         ░ ░
*/
//focus less on how much problem you should solve within a fixed time and focus more on getting the problem solved and
//learning something from it
#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define rep(i,a,b) for(ll i=a; i<b; i++)
#define per(i,a,b) for(ll i=a; i>=b; i--)
#define ll long long int
#define ld long double
#define vi vector<ll>
#define vii vector <pair<ll,ll> >
#define sedes set <ll, greater <ll> >
#define seasc set <ll>
#define pb push_back
#define mkp make_pair
#define ff first
#define ss second
// #define MOD 1000000007
#define prec(n) fixed<<setprecision(n)
#define maxpq priority_queue<int>
#define minpq priority_queue<int, vector<int>, greater<int> >
#define umap unordered_map<ll, ll>
#define map map<ll, ll>
#define autoit(x,it) for(auto it = x.begin(); it != x.end(); it++)
#define mems(a, i) memset(a, i, sizeof(a))
#define endl '\n'
#define all(v) v.begin(),v.end()
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define deba(a) cout << #a << " " <<a << endl;
ll MOD;
ll power(ll a, ll n)
{
	ll res = 1;
	while (n > 0)
	{
		if (n % 2 == 0)
			a = ((a % MOD) * (a % MOD)) % MOD, n /= 2;
		else
			res = ((res % MOD) * (a % MOD)) % MOD , n--;
	}
	return res;
}
int main()
{
	fast;
#ifndef ONLINE_JUDGE
	freopen("D:\\input.txt", "r", stdin);
	freopen("D:\\output.txt", "w", stdout);
#endif
	int t = 1;
	// cin >> t;
	while (t--)
	{
		ll n, x, m;
		cin >> n >> x >> MOD;

		ll bcy = x, cy = 0, ncy = 0, nbcy = 1;

		vi vis(MOD + 1, 0);
		vi idx(MOD + 1, 0);
		vi cys;
		ll br = -1;
		while (true)
		{
			ll y = power(x, 2) % MOD;
			// cout << y << " ";
			if (vis[y])
			{
				if (y == br)
					break;
				else if (br == -1)
					br = y;
				bcy -= y;
				cy += y;
				ncy++;
				nbcy--;
				cys.pb(y);
			}
			else
			{
				bcy += y;
				nbcy++;
				vis[y] = 1;
			}
			x = y;
		}

		// deba(bcy);
		// deba(cy);

		ll sum = 0, left = 0;
		ll sz = (n - nbcy) / ncy;
		ll j = (n - nbcy) % ncy;
		// deba(sz);
		// deba(j);
		rep(i, 0, j)
		left += cys[i];
		sum = bcy + (cy * sz) + left;
		cout << sum << endl;



	}
	return 0;
}