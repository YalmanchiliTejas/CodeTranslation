#include <bits/stdc++.h>

using namespace std;
//using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;
double PI = 4*atan(1);

ll N, mn = MOD, mn1 = 0, mx = 0, mx1 = MOD; 
vector<pair<ll,ll>> posi;

int main() {
	cin >> N;
	F0R(i,N) {
		pair<ll,ll> x; cin >> x.f >> x.s;
		if (x.f>x.s) swap(x.f,x.s);
		mn = min(mn,x.f);
		mn1 = max(mn1,x.f);
		mx = max(mx,x.s);
		mx1 = min(mx1,x.s);
		posi.pb(x);
	}
	ll ans = (mn1-mn)*(mx-mx1);
	sort(posi.begin(),posi.end());
	reverse(posi.begin(),posi.end());
	multiset<ll> coor;
	for (auto a: posi) coor.insert(a.s);
	for (auto a: posi) {
		coor.erase(coor.find(a.s));
		coor.insert(a.f);
		ans = min(ans,(mx-mn)*(*prev(coor.end())-*coor.begin()));
	}
	cout << ans;
}