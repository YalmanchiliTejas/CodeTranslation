#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define mk make_pair
#define mt make_tuple
#define MOD 998244353
#define fo(i,a,b) for(i=a;i<b;i++)
#define foe(i,a,b) for(i=a;i<=b;i++)
#define all(x) x.begin(), x.end()
#define vi vector<int>
#define vl vector <long long int>
#define pii pair <int,int>
#define pll pair <long long int, long long int>
#define vpii vector< pair<int,int> >
#define vpll vector < pair <long long int,long long int> >
#define boost ios::sync_with_stdio(false); cin.tie(0)
using namespace std;
const int inf = 1e9 + 5;
const ll inf64 = 1e18 + 5;

int main()
{
	boost;
	ll n, x, m, i;
	cin >> n >> x >> m;
	
	unordered_map <ll, ll> mp;
	mp[x] = 0;
	
	vector <ll> v;
	v.pb(x);
	
	ll ind = -1;
	fo(i, 1, n) {
		x = (1LL * x * x) % m;
		if(mp.find(x) != mp.end()) {
			ind = mp[x];
			break;
		}
		mp[x] = i;
		v.pb(x);
	}
	if(ind == -1) cout << accumulate(all(v), 0ll);
	else {
		ll ans = accumulate(all(v), 0ll);
		ll rem = n - v.size();
		ll num = v.size() - mp[x];
		
		ll sum = accumulate(v.begin() + ind, v.end(), 0ll);
		ans += sum * (rem / num);
		
		if(rem % num) ans += accumulate(v.begin() + ind, v.begin() + ind + rem % num, 0ll);
		cout << ans;
	}
}
