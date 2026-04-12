#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vz;
typedef vector<vz> vvz;
typedef pair<ll, ll> pll;
#define sz(x) int((x).size())
#define fo(i,n) for(ll i=0; i<(n); i++)
#define FO(i,a,b) for(ll i=(a); i!=(b); i+=(b)>(a)?1:-1)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(c) c.begin(), c.end()
#define F first
#define S second
#define os(x) cout<<x<<' '
#define on(x) cout<<x<<"\n"
#define nl cout<<"\n"
#define maxe(x) max_element(all(x))-(x).begin()
#define mine(x) min_element(all(x))-(x).begin()
const ll P=1e9+7;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("C:\\Users\\ASISH\\Desktop\\coding\\input1.txt", "r", stdin);
	freopen("C:\\Users\\ASISH\\Desktop\\coding\\output1.txt", "w", stdout);
#endif

	int tc=1;
	fo(q, tc)
	{
		ll n, ans=0;
		cin>>n;
		vll a(n), psum(n);
		fo(i, n) cin>>a[i];
		FO(i, 1, n){
			psum[i]=(psum[i-1]+a[i-1])%P;
			ans=(ans + (psum[i]*a[i])%P)%P;
		}
		on(ans);
	}
	cerr << "Time : " << ((double)clock()) / (double)CLOCKS_PER_SEC << "s\n";
	return 0;
}