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
#define pi pair<ll,ll>
#define vii vector <pair<ll,ll> >
#define sedes set <ll, greater <ll> >
#define seasc set <ll>
#define pb push_back
#define mkp make_pair
#define ff first
#define ss second
#define MOD 1000000007
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
		ll n;
		cin >> n;
		string s;
		cin >> s;

		vi a(n, -1);
		// bool ans = false;
		rep(i, 0, 2)
		{
			rep(j, 0, 2)
			{
				ll z, y;
				s[0] == 'o' ? z = 0 : z = 1;
				a[0] = i, a[1] = j;
				a[n - 1] = (a[0] ^ a[1]) ^ z;
				// cout << a[n - 1];
				rep(k, 1, n - 2)
				{
					ll z;
					s[k] == 'o' ? z = 0 : z = 1;
					a[k + 1] = ((z ^ a[k]) ^ a[k - 1]);
					// cout << a[k + 1] << endl;
				}
				// ll z;
				s[n - 2] == 'o' ? z = 0 : z = 1;
				s[n - 1] == 'o' ? y = 0 : y = 1;
				if (a[n - 1] == a[n - 2]^z ^ a[n - 3] and a[0] == a[n - 2] ^ y ^ a[n - 1]) {
					rep(l, 0, n)
					a[l] == 0 ? cout << 'S' : cout << 'W';
					return 0;
				}
			}
		}
		cout << -1;
	}
	return 0;
}