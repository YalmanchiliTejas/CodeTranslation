#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<utility>
#include<cmath>
#include<climits>
#include<queue>
#include<stack>
#include<numeric>
#include<set>
#include<iomanip>
#include<map>
#include<type_traits>
#include<tuple>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
const int mod = 1000000007;


int main(){
	ll a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	ll ans = LLONG_MAX;
	for(ll i = 0; i <= max(x, y); ++i){
		ll ea = max(x - i, (ll)0), eb = max(y - i, (ll)0);

		ll value = c * i * 2 + a * ea + b * eb;
		ans = min(ans, value);
	}

	cout << ans << endl;

}