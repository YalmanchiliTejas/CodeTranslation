#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef	long long ll;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef set<int> si;
typedef map<int,int> mii;
typedef map<ll,ll> mll;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef pair<ll, pll> plll;
typedef vector<pair<int, pii>> viii;
#define fi first
#define se second
#define pi 3.141592653589793
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define tc int tt;cin>>tt;while(tt--)
#define pqmax priority_queue<int>
#define pqmin priority_queue<int,vi,greater<int>>
#define fio ios_base::sync_with_stdio(0), cin.tie(NULL)
#define tc_g int tt;cin>>tt;for(int ti=1;ti<=tt;ti++)
#define case_g "Case #"<<ti<<": "
#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"
#define sleep for (int i = 1, a;i < 100000000;i++, a = a * a)
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> ranked_pairset;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ranked_set;
typedef tree<int, int, less<int>, rb_tree_tag, tree_order_statistics_node_update> ranked_map;

int main() {
	fio;
	int n;
	cin >> n;
	vl a(n);
	for (int i = 0;i < n;i++)
		cin >> a[i];
	ll s = accumulate(all(a), 0LL) % mod;
	s *= s;
	for (int i = 0;i < n;i++)
		s = (s - a[i] * a[i] % mod + mod) % mod;
	s = s * ((mod + 1) / 2) % mod;
	cout << s << '\n';
}
