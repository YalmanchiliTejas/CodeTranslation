#include <bits/stdc++.h>
using namespace std;

#define cnd(c, a, b) (c ? a : b);
#define fl(x,y,z) for(int x=y;x<z;x++)
#define fe(x,y,z) for(int x=y;x<=z;x++)
#define fge(x,y,z) for(int x=y;x>=z;x--)

#define debug(x) std::cerr << #x << " --> " << x << "\n";
#define fastIO std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);
#define pb push_back
#define pob pop_back
 
#define ln '\n'
typedef long long int ll;

ll mod=1e9+7;

void decrypt() {
	ll n;
	ll x, m;

	ll size;
	unordered_map<ll, ll> mp;
	vector<ll> vec, csum;

	cin>>n;
	cin>>x>>m;
	ll cval, val;
	cval = x;
	val = (cval*cval)%m;
	size = 0;
	ll flag = 0;
	while(mp.find(cval)==mp.end()) {
		mp[cval] = size;
		if(cval==0) {
			flag = 1;
		}
		vec.pb(cval);
		if(size==0) {
			csum.pb(cval);
		}
		else {
			csum.pb(csum[size-1] + cval);
		}
		size++;
		cval = val;
		val = (cval*cval)%m;
	}
	ll ind = mp[cval];
	// cout<<"DE: "<<cval<<" "<<ind<<ln;
	// fl(i,0,size) {
	// 	cout<<vec[i]<<" ";
	// }
	// cout<<ln;
	// fl(i,0,size) {
	// 	cout<<csum[i]<<" ";
	// }
	// cout<<ln;
	ll ans;
	ll asize = size-ind;
	// cout<<"DE:asize "<<asize<<ln;
	if(n>size) {
		ans = csum[size-1];
		n -= size;
		ll minval = (ind==0 ? 0 : csum[ind-1]);
		ans += (n/asize)*(csum[size-1]-minval);
		if(n%asize>0) {
			ans += csum[(n%asize)-1+ ind] - minval;
		}
	} else {
		ans = csum[n-1];
	}
	cout<<ans<<ln;
	return;
}

int main() {
    fastIO
    int t = 1;
    // cin >> t;
    fl(i,0,t) {
    	// cout << "Case #"<< i+1 <<": ";
    	decrypt();
    }
    return 0;
}