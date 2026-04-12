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
	ll n, ans, tmp, sum;
	vector<ll> in, cum;
	cin>>n;
	sum = 0;
	fl(i,0,n) {
		cin>>tmp;
		sum += tmp;
		in.pb(tmp);
	}
	tmp = 0;
	fl(i,0,n) {
		sum -= in[i];
		cum.pb(sum);
	}
	ans = 0;
	fl(i,0,n-1) {
		ans = (ans%mod + (in[i]%mod)*(cum[i]%mod))%mod;
	}
	cout<<((ans+mod)%mod)<<ln;
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