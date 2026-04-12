#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

#define LB(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define UB(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef unsigned long long ull;
typedef long double ld; 
// typedef vector vec;

ll mod = 1e9 + 7;

#define each(a,x) for( auto &a:(x))
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define repr(i, n) for (ll i = (n) - 1; i >= 0; i--)
#define rep2(i, l, r) for (ll i = (l); i < (r); i++)
#define rep2r(i, l, r) for (ll i = (r) - 1; i >= (l); i--)
#define range(a) a.begin(), a.end()
// cout<<endl;


int main()
{
	fastio();
	int n, m;
	cin>>n>>m;
	if(n > m) cout<<"No\n";
	else cout<<"Yes\n";
}
